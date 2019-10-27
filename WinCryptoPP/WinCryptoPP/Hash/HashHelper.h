#pragma once
#include <string>
#include <hex.h>
#include <md5.h>
#include <sha.h>
#include <files.h>
#include <windows.h>

using namespace CryptoPP;

std::string CalMD5ByFile(char* pszFileName);				//计算文件的MD5值
std::string CalMD5ByMem(PBYTE pData, DWORD dwDataSize);		//计算内存数据的MD5值
std::string CalSha1ByFile(char* pszFileName);				//计算文件的SHA1值
std::string CalSha1ByMem(PBYTE pData, DWORD dwDataSize);	//计算内存数据的SHA1值
std::string CalSha256ByFile(char* pszFileName);				//计算文件的SHA256值
std::string CalSha256ByMem(PBYTE pData, DWORD dwDataSize);	//计算内存数据的SHA256值
