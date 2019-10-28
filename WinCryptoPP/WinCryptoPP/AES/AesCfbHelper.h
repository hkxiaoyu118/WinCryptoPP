#pragma once
#include <aes.h>
#include <modes.h>
#include <hex.h>

using namespace CryptoPP;

class AesCfbHelper
{
public:
	AesCfbHelper(std::string key, std::string iv);
	~AesCfbHelper();
public:
	std::string EncryptData(std::string data, std::string& errorString);
	std::string DecryptData(std::string cryptedData, std::string& errorString);
private:
	CFB_Mode<AES>::Encryption m_encryption;		//¼ÓÃÜÆ÷
	CFB_Mode<AES>::Decryption m_decryption;		//½âÃÜÆ÷
};

