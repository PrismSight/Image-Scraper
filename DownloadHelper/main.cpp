#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <WinInet.h>
#include <tchar.h>
#include <urlmon.h>
#include "SecureNetwork.h"
#include "RequestURL.h"

using namespace std;
[System::STAThread]
int _tmain(int argc, _TCHAR* argv[])
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	DownloadHelper::RequestURL^ xx = gcnew DownloadHelper::RequestURL();
	xx->ShowDialog();
	/*
	std::string URL = "", Directory = "";
	std::cout << "URL: ";
	std::getline(std::cin, URL);
	std::cout << "Directory:";
	std::getline(std::cin, Directory);

	if (!DownloadImgFromURL(URL, Directory))
	{
		std::cout << "Something went wrong!" << std::endl;
	}
	*/
	std::cout << "DONE" << '\n';
	return 0;
}