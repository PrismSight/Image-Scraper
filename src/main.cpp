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
	::ShowWindow(::GetConsoleWindow(), SW_HIDE); // Hide the console
	ImageScraper::RequestURL^ xx = gcnew ImageScraper::RequestURL();
	xx->ShowDialog();
	return 0;
}