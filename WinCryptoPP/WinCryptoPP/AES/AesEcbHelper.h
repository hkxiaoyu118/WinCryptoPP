#pragma once
#include <aes.h>
#include <modes.h>
#include <hex.h>

using namespace CryptoPP;

class AesEcbHelper
{
public:
	AesEcbHelper(std::string key);
	~AesEcbHelper();
public:
	std::string EncryptData(std::string data, std::string& errorString);
	std::string DecryptData(std::string cryptedData, std::string& errorString);
private:
	ECB_Mode<AES>::Encryption m_encryption;		//¼ÓÃÜÆ÷
	ECB_Mode<AES>::Decryption m_decryption;		//½âÃÜÆ÷
};

