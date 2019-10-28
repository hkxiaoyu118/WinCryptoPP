#include "AesCbcHelper.h"

AesCbcHelper::AesCbcHelper(std::string key, std::string iv)
{
	m_encryption.SetKeyWithIV((byte*)key.c_str(), key.length(), (byte*)iv.c_str());
	m_decryption.SetKeyWithIV((byte*)key.c_str(), key.length(), (byte*)iv.c_str());
}


AesCbcHelper::~AesCbcHelper()
{

}
 

std::string AesCbcHelper::EncryptData(std::string data, std::string& errorString)
{
	std::string cryptResult;

	try
	{
		StreamTransformationFilter encryptor(m_encryption, new HexEncoder(new StringSink(cryptResult)));
		encryptor.Put((byte*)data.c_str(), data.length());
		encryptor.MessageEnd();
	}
	catch (const CryptoPP::Exception & e)
	{
#if _DEBUG
		std::cerr << e.what() << std::endl;
#endif
		errorString = e.what();
	}

	return cryptResult;
}


std::string AesCbcHelper::DecryptData(std::string cryptedData, std::string& errorString)
{
	std::string originalData;

	try
	{
		HexDecoder decryptor(new StreamTransformationFilter(m_decryption, new StringSink(originalData)));
		decryptor.Put((byte*)cryptedData.c_str(), cryptedData.length());
		decryptor.MessageEnd();
	}
	catch (const CryptoPP::Exception & e)
	{
#if _DEBUG
		std::cerr << e.what() << std::endl;
#endif
		errorString = e.what();
	}

	return originalData;
}