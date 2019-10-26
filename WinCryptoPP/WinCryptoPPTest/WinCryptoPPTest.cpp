// WinCryptoPPTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include "../WinCryptoPP/Hash/HashHelper.h"
#include "../WinCryptoPP/AES/AesHelper.h"

#pragma comment(lib, "..\\WinCryptoPP\\Libs\\lib\\Debug\\cryptlib.lib")
#pragma comment(lib, "..\\Debug\\WinCryptoPP.lib")


int _tmain(int argc, _TCHAR* argv[])
{
// 	HashHelper helper;
// 	std::string filePath = "C:\\Users\\hkxiaoyu118\\AppData\\Local\\Discord\\Update.exe";
// 	std::string result1=helper.CalMD5FromFile((char *)filePath.c_str());
// 	printf("MD5:%s\n", result1.c_str());
// 	std::string result2 = helper.CalSha1FromFile((char *)filePath.c_str());
// 	printf("MD5:%s\n", result2.c_str());
// 	std::string result3 = helper.CalSha256FromFile((char *)filePath.c_str());
// 	printf("MD5:%s\n", result3.c_str());

	AesHelper helper;
	std::string text = "哈哈哈哈，孙肥肥xxxxx";
	std::string key = "qwertyuioplkjhgf";
	std::string result1 = helper.AesEncrypt(text, key);
	std::string result2 = helper.AesDecrypt(result1, key);
	std::cout << result2 << std::endl;
	system("pause");
	return 0;
}

