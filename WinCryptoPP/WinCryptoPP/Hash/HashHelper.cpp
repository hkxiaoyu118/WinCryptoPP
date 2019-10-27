#include "HashHelper.h"

std::string CalMD5ByFile(char* pszFileName)
{
	std::string value;
	MD5 md5;
	FileSource(pszFileName, true, new HashFilter(md5, new HexEncoder(new StringSink(value))));
	return value;
}

std::string CalMD5ByMem(PBYTE pData, DWORD dwDataSize)
{
	std::string value;
	MD5 md5;
	StringSource(pData, dwDataSize, true, new HashFilter(md5, new HexEncoder(new StringSink(value))));
	return value;
}

std::string CalSha1ByFile(char* pszFileName)
{
	std::string value;
	SHA1 sha1;
	FileSource(pszFileName, true, new HashFilter(sha1, new HexEncoder(new StringSink(value))));
	return value;
}

std::string CalSha1ByMem(PBYTE pData, DWORD dwDataSize)
{
	std::string value;
	SHA1 sha1;
	StringSource(pData, dwDataSize, true, new HashFilter(sha1, new HexEncoder(new StringSink(value))));
	return value;
}

std::string CalSha256ByFile(char* pszFileName)
{
	std::string value;
	SHA256 sha256;
	FileSource(pszFileName, true, new HashFilter(sha256, new HexEncoder(new StringSink(value))));
	return value;
}

std::string CalSha256ByMem(PBYTE pData, DWORD dwDataSize)
{
	std::string value;
	SHA256 sha256;
	StringSource(pData, dwDataSize, true, new HashFilter(sha256, new HexEncoder(new StringSink(value))));
	return value;
}