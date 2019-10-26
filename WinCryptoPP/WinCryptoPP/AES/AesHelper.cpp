#include "AesHelper.h"


AesHelper::AesHelper()
{
}


AesHelper::~AesHelper()
{
}

std::string AesHelper::AesEncrypt(const std::string& originalData, const std::string& aesKey)
{
	std::string encryptResult;
	//加密器
	AESEncryption aesEncryptor;
	//加密原始数据块
	unsigned char inBlock[AES::BLOCKSIZE];
	//加密后密文数据块
	unsigned char outBlock[AES::BLOCKSIZE];
	//必须设置为全0
	unsigned char xorBlock[AES::BLOCKSIZE];

	DWORD dwOffset = 0;
	BYTE* pEncryptData = 0;
	DWORD dwEncryptDataSize = 0;

	//获取原始数据的内存指针
	const char* pOriginalData = (const char*)originalData.c_str();
	//计算原始数据的实际长度
	DWORD dwOriginalDataSize = originalData.length();
	//计算原始数据的长度,按照128位对齐,不够则填0对齐(nopadding填充方式)
	DWORD dwQuotient = dwOriginalDataSize / AES::BLOCKSIZE;	//商
	DWORD dwRemaind = dwOriginalDataSize % AES::BLOCKSIZE;	//余数
	if (dwRemaind != 0)
	{
		dwQuotient++;
	}

	//申请动态内存
	dwEncryptDataSize = dwQuotient*AES::BLOCKSIZE;
	pEncryptData = new BYTE[dwEncryptDataSize];
	if (pEncryptData == NULL)
	{
		return encryptResult;
	}

	//设置密钥
	aesEncryptor.SetKey((const unsigned char*)aesKey.c_str(), aesKey.length());

	do 
	{
		//置零
		::RtlZeroMemory(inBlock, AES::BLOCKSIZE);
		::RtlZeroMemory(xorBlock, AES::BLOCKSIZE);
		::RtlZeroMemory(outBlock, AES::BLOCKSIZE);

		if (dwOffset <= (dwOriginalDataSize - AES::BLOCKSIZE))
		{
			::RtlCopyMemory(inBlock, (PVOID)(pOriginalData + dwOffset), AES::BLOCKSIZE);
		}
		else
		{
			::RtlCopyMemory(inBlock, (PVOID)(pOriginalData + dwOffset), (dwOriginalDataSize - dwOffset));
		}

		//加密
		aesEncryptor.ProcessAndXorBlock(inBlock, xorBlock, outBlock);
		//构造
		::RtlCopyMemory((PVOID)(pEncryptData + dwOffset), outBlock, AES::BLOCKSIZE);
		//更新数据
		dwOffset = dwOffset + AES::BLOCKSIZE;
		dwQuotient--;
	} while (dwQuotient > 0);

	encryptResult.resize(dwEncryptDataSize);
	::RtlCopyMemory((char *)encryptResult.c_str(), pEncryptData, dwEncryptDataSize);
	delete[] pEncryptData;
	return encryptResult;
}

std::string AesHelper::AesDecrypt(const std::string& encryptData, const std::string& aesKey)
{
	std::string originalResult;
	// 解密器
	AESDecryption aesDecryptor;
	// 解密密文数据块
	unsigned char inBlock[AES::BLOCKSIZE];
	// 解密后后明文数据块
	unsigned char outBlock[AES::BLOCKSIZE];
	// 必须设定全为0
	unsigned char xorBlock[AES::BLOCKSIZE];

	DWORD dwOffset = 0;
	BYTE* pDecryptData = NULL;
	DWORD dwDecryptDataSize = 0;

	const char* pEncryptData = encryptData.c_str();
	DWORD dwEncryptData = encryptData.length();
	//计算密文的长度,并按照128位对齐,不够则填充0对齐
	DWORD dwQuotient = dwEncryptData / AES::BLOCKSIZE;	//商
	DWORD dwRemaind = dwEncryptData % AES::BLOCKSIZE;	//余数
	if (dwRemaind != 0)
	{
		dwQuotient++;
	}

	//申请动态内存
	dwDecryptDataSize = dwQuotient*AES::BLOCKSIZE;
	pDecryptData = new BYTE[dwDecryptDataSize];
	if (pDecryptData == NULL)
	{
		return originalResult;
	}

	//设置密钥
	aesDecryptor.SetKey((const unsigned char*)aesKey.c_str(), aesKey.length());

	do 
	{
		// 置零
		::RtlZeroMemory(inBlock, AES::BLOCKSIZE);
		::RtlZeroMemory(xorBlock, AES::BLOCKSIZE);
		::RtlZeroMemory(outBlock, AES::BLOCKSIZE);

		// 获取解密块
		if (dwOffset <= (dwDecryptDataSize - AES::BLOCKSIZE))
		{
			::RtlCopyMemory(inBlock, (PVOID)(pEncryptData + dwOffset), AES::BLOCKSIZE);
		}
		else
		{
			::RtlCopyMemory(inBlock, (PVOID)(pEncryptData + dwOffset), (dwEncryptData - dwOffset));
		}

		//解密
		aesDecryptor.ProcessAndXorBlock(inBlock, xorBlock, outBlock);
		//构造
		::RtlCopyMemory((PVOID)(pDecryptData + dwOffset), outBlock, AES::BLOCKSIZE);
		//更新数据
		dwOffset = dwOffset + AES::BLOCKSIZE;
		dwQuotient--;
	} while (dwQuotient > 0);

	//返回数据
	originalResult.resize(dwDecryptDataSize);

	::RtlCopyMemory((char *)originalResult.c_str(), pDecryptData, dwDecryptDataSize);
	delete[] pDecryptData;
	return originalResult;
}