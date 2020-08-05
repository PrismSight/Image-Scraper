#include "ImgScraper.h"
std::vector<std::string> GetAllImgURLs(std::string URL)
{
	std::vector<std::string> ret;

	std::string answer = "";
	if (URL[URL.length() - 1] != '/')
		URL += '/';

	SecureNetwork net;
	std::size_t firstDash = 0, beginChar = 0;
	if (URL.compare(0, 5, "https") == 0)
	{
		firstDash = URL.find('/', 8);
		beginChar = 8;
	}
	else if (URL.compare(0, 4, "http") == 0)
	{
		firstDash = URL.find('/', 7);
		beginChar = 7;
	}
	else
	{
		firstDash = URL.find('/', 0);
	}
	std::string host = URL.substr(beginChar, firstDash - beginChar);
	std::string page = URL.substr(firstDash, URL.find_last_of('/') - firstDash);
	answer = net.SendHTTPSRequest_GET(host, page, "");
	if (answer.length() == 0)
	{
		return ret;
	}
	std::size_t URLnr = 0, match = 0;
	std::string MainDir = URL.substr(0, URL.find_last_of('/'));

	while (true)
	{
		std::size_t First = answer.find("<img", URLnr);
		std::size_t Second = answer.find("src=\"", First);
		std::size_t Third = answer.find("\"", Second + 5);
		URLnr = Third;
		if (First == std::string::npos) break;
		std::string IMG_URL = answer.substr(Second + 5, Third - Second - 5);
		std::string FullIMGURL;
		if (IMG_URL.compare(0, 4, "http") == 0)
		{
			FullIMGURL = IMG_URL;
		}
		else if (IMG_URL.compare(0, 2, "//") == 0)
		{
			FullIMGURL = "https:" + IMG_URL;
		}
		else if (IMG_URL.compare(0, 1, "/") == 0)
		{
			FullIMGURL = MainDir + IMG_URL;
		}
		else continue;

		ret.push_back(FullIMGURL);
	}
	return ret;
}
bool DownloadImgFromURL(std::string URL, std::string Directory)
{
	size_t PosOfLastDash = URL.find_last_of("/") + 1;
	size_t PosOfQuestionMark = URL.find('?', PosOfLastDash);
	std::string FileName = Directory + '\\' + URL.substr(PosOfLastDash, (PosOfQuestionMark == std::string::npos)? URL.length()-1 : PosOfQuestionMark - PosOfLastDash);
	std::wstring FileNameW = std::wstring(FileName.begin(), FileName.end());
	std::wstring stemp = std::wstring(URL.begin(), URL.end());

	DWORD ftyp = GetFileAttributesA(Directory.c_str()); // Check the directory a second time, just to be sure!
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;

	HRESULT hr = URLDownloadToFile(NULL, stemp.c_str(), FileNameW.c_str(), 0, NULL);
	if (hr == S_OK)
		return true;
	else 
		return false;
}



bool DownloadAllImagesOnPage(std::string URL, std::string Directory)
{
	DWORD ftyp = GetFileAttributesA(Directory.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;

	std::string answer = "";
	if (URL[URL.length() - 1] != '/')
		URL += '/';

	SecureNetwork net;
	std::size_t firstDash = 0, beginChar = 0;
	if (URL.compare(0, 5, "https") == 0)
	{
		firstDash = URL.find('/', 8);
		beginChar = 8;
	}
	else if (URL.compare(0, 4, "http") == 0)
	{
		firstDash = URL.find('/', 7);
		beginChar = 7;
	}
	else
	{
		firstDash = URL.find('/', 0);
	}
	std::string host = URL.substr(beginChar, firstDash - beginChar);
	std::string page = URL.substr(firstDash, URL.find_last_of('/') - firstDash);
	answer = net.SendHTTPSRequest_GET(host, page, "");
	if (answer.length() == 0)
	{
		return false;
	}
	std::size_t  URLnr = 0, match = 0;
	std::wstring DirectoryW = std::wstring(Directory.begin(), Directory.end());
	// CreateDirectory(DirectoryW.c_str(), NULL);

	std::string MainDir = URL.substr(0, URL.find_last_of('/'));

	while (true)
	{
		std::size_t First = answer.find("<img", URLnr);
		std::size_t Second = answer.find("src=\"", First);
		std::size_t Third = answer.find("\"", Second + 5);
		URLnr = Third;
		if (First == std::string::npos) break;
		std::string IMG_URL = answer.substr(Second + 5, Third - Second - 5);
		std::string FileName = Directory + '\\' + IMG_URL.substr(IMG_URL.find_last_of("/"), IMG_URL.length());
		std::wstring FileNameW = std::wstring(FileName.begin(), FileName.end());

		std::string FullIMGURL;
		if (IMG_URL.compare(0, 4, "http") == 0)
		{
			FullIMGURL = IMG_URL;
		}
		else if (IMG_URL.compare(0, 2, "//") == 0)
		{
			FullIMGURL = "https:" + IMG_URL;
		}
		else if (IMG_URL.compare(0, 1, "/") == 0)
		{
			FullIMGURL = MainDir + IMG_URL;
		}
		else continue;

		std::wstring stemp = std::wstring(FullIMGURL.begin(), FullIMGURL.end());
		HRESULT hr = URLDownloadToFile(NULL, stemp.c_str(), FileNameW.c_str(), 0, NULL);
		std::cout << answer.substr(Second + 5, Third - Second - 5) << '\n';

	}
	return true;
}