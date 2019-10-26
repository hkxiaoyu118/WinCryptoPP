#pragma once
#include <string>
#include <hex.h>
#include <md5.h>
#include <sha.h>
#include <files.h>
#include <windows.h>

using namespace CryptoPP;

class HashHelper
{
public:
	HashHelper();
	~HashHelper();
	
public:
	std::string CalMD5FromFile(char* pszFileName);				//计算文件的MD5值
	std::string CalMD5FromMem(PBYTE pData, DWORD dwDataSize);	//计算内存数据的MD5值
	std::string CalSha1FromFile(char* pszFileName);				//计算文件的SHA1值
	std::string CalSha1FromMem(PBYTE pData, DWORD dwDataSize);	//计算内存数据的SHA1值
	std::string CalSha256FromFile(char* pszFileName);			//计算文件的SHA256值
	std::string CalSha256FromMem(PBYTE pData, DWORD dwDataSize);//计算内存数据的SHA256值
};

