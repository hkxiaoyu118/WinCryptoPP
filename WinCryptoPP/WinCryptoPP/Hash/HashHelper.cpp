#include "HashHelper.h"

HashHelper::HashHelper()
{
}

HashHelper::~HashHelper()
{
}

std::string HashHelper::CalMD5FromFile(char* pszFileName)
{
	std::string value;
	MD5 md5;
	FileSource(pszFileName, true, new HashFilter(md5, new HexEncoder(new StringSink(value))));
	return value;
}

std::string HashHelper::CalMD5FromMem(PBYTE pData, DWORD dwDataSize)
{
	std::string value;
	MD5 md5;
	StringSource(pData, dwDataSize, true, new HashFilter(md5, new HexEncoder(new StringSink(value))));
	return value;
}

std::string HashHelper::CalSha1FromFile(char* pszFileName)
{
	std::string value;
	SHA1 sha1;
	FileSource(pszFileName, true, new HashFilter(sha1, new HexEncoder(new StringSink(value))));
	return value;
}

std::string HashHelper::CalSha1FromMem(PBYTE pData, DWORD dwDataSize)
{
	std::string value;
	SHA1 sha1;
	StringSource(pData, dwDataSize, true, new HashFilter(sha1, new HexEncoder(new StringSink(value))));
	return value;
}

std::string HashHelper::CalSha256FromFile(char* pszFileName)
{
	std::string value;
	SHA256 sha256;
	FileSource(pszFileName, true, new HashFilter(sha256, new HexEncoder(new StringSink(value))));
	return value;
}

std::string HashHelper::CalSha256FromMem(PBYTE pData, DWORD dwDataSize)
{
	std::string value;
	SHA256 sha256;
	StringSource(pData, dwDataSize, true, new HashFilter(sha256, new HexEncoder(new StringSink(value))));
	return value;
}