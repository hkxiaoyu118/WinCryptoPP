// WinCryptoPPTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include "../WinCryptoPP/Hash/HashHelper.h"
#include "../WinCryptoPP/AES/AesHelper.h"
#include "../WinCryptoPP/AES/AesEcbHelper.h"
#include "../WinCryptoPP/AES/AesCbcHelper.h"
#include "../WinCryptoPP/AES/AesCbcCtsHelper.h"
#include "../WinCryptoPP/AES/AesCfbHelper.h"
#include "../WinCryptoPP/AES/AesCtrHelper.h"
/*#include "../WinCryptoPP/RSA/RSAHelper.h"*/

#pragma comment(lib, "..\\WinCryptoPP\\Libs\\lib\\Debug\\cryptlib.lib")
#pragma comment(lib, "..\\Debug\\WinCryptoPP.lib")

using namespace std;

char g_szPubKey[] = "30819D300D06092A864886F70D010101050003818B0030818702818100F0CE882D7CCB990323A6DB1B775EBE8F2910BFE75B4B580EF8C5089BB25FEDEEABCE2BBD2AC64A138E47F96A6C39152FE98067C0B4F5DC28F8D9394325ADB12A90A9598FF7A2A7211DEF974FC8A005D0CBCDE059FB8F7F9D214C5BAC2532CEB8EC4041AEAB19E80B8C4020F4A50102F9E738647E2384EA2FCD30C3681559CF6F020111";
char g_szPrivKey[] = "30820275020100300D06092A864886F70D01010105000482025F3082025B02010002818100F0CE882D7CCB990323A6DB1B775EBE8F2910BFE75B4B580EF8C5089BB25FEDEEABCE2BBD2AC64A138E47F96A6C39152FE98067C0B4F5DC28F8D9394325ADB12A90A9598FF7A2A7211DEF974FC8A005D0CBCDE059FB8F7F9D214C5BAC2532CEB8EC4041AEAB19E80B8C4020F4A50102F9E738647E2384EA2FCD30C3681559CF6F020111028180210D49E8203005F15F3F0F03C5170B18AB4892CF70EC39434F52426FB91C39C162E0100AE7C0DCFDAA1DF50E9B67351AA7942251AA68051EB8BE7145739A599220030CF5E35ED4DEA41DD6E955722AE46153339FE7417BD00ADF53B368EAB6E71FAE0F7F394A34C91612B0F11AEC5525DB84DD982E6BF10CE74F177FA51ADC51024100F80296900AF134CCC5AC12C58D741C735F5EE9CBDFB8C1B1EB039BF078E37B09322074193B7B0AE5A60B544DDDB9159294E91744404A2C7CDF96287F5483D691024100F8908925066C3ED9AC8EAFE63A59D56FCBEC354A3DD513489DEDA70E42338CD2AEBDEEF685148123B31A55CA27B2A59CA53E2352DA284F30585A5D6B571245FF02410091E367A0066FC4B4B083565616F901AD4728C5C3384E900E4E021F7E653A849BFF5E6269320C24871661046A09F4670AEE2EC264620D8394BFC1BD781398D891024057BA8AC1C608162EB55F896050D46972C0717C38520EF7BF46CC5914175D7CFF107F4547F2BBF157E4DC1E47594E1C55677F57C2E395C19897A76C44009D09A5024100BBB92D3E8776B52FA20303E39FE8AE862637BB75880D82C6580C3217445C4A95BFB6E94120AD62AADC313418A350FF21B0ED861848626CC0F55936F750B44FC4";


int _tmain(int argc, _TCHAR* argv[])
{
	//HASH计算测试
// 	std::string filePath = "C:\\Users\\hkxiaoyu118\\AppData\\Local\\Discord\\Update.exe";
// 	std::string result1=CalMD5ByFile((char *)filePath.c_str());
// 	printf("MD5:%s\n", result1.c_str());
// 	std::string result2 = CalSha1ByFile((char *)filePath.c_str());
// 	printf("SHA1:%s\n", result2.c_str());
// 	std::string result3 = CalSha256ByFile((char *)filePath.c_str());
// 	printf("SHA256:%s\n", result3.c_str());

	//AES对称加密测试
// 	AesHelper helper;
// 	std::string text = "哈哈哈哈，孙肥肥xxxxx";
// 	std::string key = "qwertyuioplkjhgf";
// 	std::string result1 = helper.AesEncrypt(text, key);
// 	std::string result2 = helper.AesDecrypt(result1, key);
// 	std::cout << result2 << std::endl;


	//RSA测试
// 	char szPrivateFile[] = "privatefile";
// 	char szPublicFile[] = "publicfile";
// 	char szSeed[] = "DemonGanDemonGansdjlkfjsdlk";
// 
// 	char szOriginalString[] = "I am DemonGan";
// 
// 	/* 密钥在文件方式 */
// 	// 生成RSA公私密钥对
// 	GenerateRSAKey(1024, szPrivateFile, szPublicFile, (BYTE*)szSeed, ::lstrlen(szSeed));
// 	// RSA公钥加密字符串
// 	string strEncryptString = RSAEncryptByFile(szOriginalString, szPublicFile, (BYTE*)szSeed, ::lstrlen(szSeed));
// 	// RSA私钥解密字符串
// 	string strDecryptString = RSADecryptByFile((char*)strEncryptString.c_str(), szPrivateFile);
// 	// 显示
// 	printf("原文字符串:\n[%d]%s\n", ::lstrlen(szOriginalString), szOriginalString);
// 	printf("密文字符串:\n[%d]%s\n", strEncryptString.length(), strEncryptString.c_str());
// 	printf("解密明文字符串:\n[%d]%s\n", strDecryptString.length(), strDecryptString.c_str());
// 
// 	printf("\n\n");
// 
// 
//  	/* 密钥在内存方式 */
//  	// RSA公钥加密字符串
//  	string strEncryptString_Mem = RSAEncryptByMem(szOriginalString, g_szPubKey, (BYTE*)szSeed, ::lstrlen(szSeed));
//  	// RSA私钥解密字符串
//  	string strDecryptString_Mem = RSADecryptByMem((char*)strEncryptString_Mem.c_str(), g_szPrivKey);
//  	// 显示
//  	printf("原文字符串:\n[%d]%s\n", ::lstrlen(szOriginalString), szOriginalString);
//  	printf("密文字符串:\n[%d]%s\n", strEncryptString_Mem.length(), strEncryptString_Mem.c_str());
//  	printf("解密明文字符串:\n[%d]%s\n", strDecryptString_Mem.length(), strDecryptString_Mem.c_str());

	while (true)
	{
		std::string errorString;
		std::string str = "深刻搭街坊立刻就撒大了房间阿里山扩大就伺机待发卢卡斯京东方了静安寺零九分卢卡斯的积分了教师劳动纠纷了撒旦解放了看就";
		std::string key = "wertyuioplkjhgfd";
		std::string iv = "1111111111111111";
		AesCtrHelper helper(key, iv);
		std::string result1 = helper.EncryptData(str, errorString);
		std::cout << result1 << std::endl;
		//result1 = "wertyuioplkjhgfd";
		std::string result2 = helper.DecryptData(result1, errorString);
		std::cout << result2 << std::endl;
	}

	system("pause");
	return 0;
}

