#pragma once
#include <aes.h>
#include <modes.h>
#include <hex.h>

using namespace CryptoPP;

class AesCtrHelper
{
public:
	AesCtrHelper(std::string key, std::string iv);
	~AesCtrHelper();
public:
	std::string EncryptData(std::string data, std::string& errorString);
	std::string DecryptData(std::string cryptedData, std::string& errorString);
private:
	CTR_Mode<AES>::Encryption m_encryption;		//¼ÓÃÜÆ÷
	CTR_Mode<AES>::Decryption m_decryption;		//½âÃÜÆ÷
};

