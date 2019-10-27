#pragma once
#include <aes.h>
#include <windows.h>

using namespace CryptoPP;

/*
	简单的AES加密算法
	使用nopadding进行填充
	解密没有去掉nopadding
*/
class AesHelper
{
public:
	AesHelper();
	~AesHelper();

public:
	std::string AesEncrypt(const std::string& originalData, const std::string& aesKey); //普通加密
	std::string AesDecrypt(const std::string& encryptData, const std::string& aesKey);	//普通解密
};

