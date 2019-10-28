#pragma once
#include <aes.h>
#include <modes.h>
#include <hex.h>

using namespace CryptoPP;

class AesCbcCtsHelper
{
public:
	AesCbcCtsHelper(std::string key, std::string iv);
	~AesCbcCtsHelper();
public:
	std::string EncryptData(std::string data, std::string& errorString);
	std::string DecryptData(std::string cryptedData, std::string& errorString);
private:
	CBC_CTS_Mode<AES>::Encryption m_encryption;		//¼ÓÃÜÆ÷
	CBC_CTS_Mode<AES>::Decryption m_decryption;		//½âÃÜÆ÷
};

