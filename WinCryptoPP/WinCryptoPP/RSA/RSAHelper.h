#pragma once
#include <hex.h>
#include <rsa.h>
#include <files.h>
#include <osrng.h>
#include <gfpcrypt.h>
#include <randpool.h>
#include <windows.h>

using namespace CryptoPP;

BOOL GenerateRSAKey(DWORD dwRSAKeyLength, char* pszPrivateKeyFileName, char* pszPublicKeyFileName, BYTE* pSeed, DWORD dwSeedLength);
std::string RSAEncryptByFile(char* pszOriginaString, char* pszPublicKeyFileName, BYTE* pSeed, DWORD dwSeedLength);
std::string RSADecryptByFile(char* pszEncryptString, char* pszPrivateKeyFileName);
std::string RSAEncryptByMem(char* pszOriginaString, char* pszMemPublicKey, BYTE* pSeed, DWORD dwSeedLength);
std::string RSADecryptByMem(char* pszEncryptString, char* pszMemPrivateKey);
RandomPool& GlobalRNG();