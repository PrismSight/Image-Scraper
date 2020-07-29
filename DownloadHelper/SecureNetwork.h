#pragma once
#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <WinInet.h>
#include "tchar.h"
#include <urlmon.h>
using namespace std;

#define BUFFERSIZE 1024
#pragma comment (lib, "Wininet.lib")
#pragma comment(lib, "urlmon.lib")
class SecureNetwork
{
public:
	SecureNetwork();
	~SecureNetwork(); 
	string SendHTTPSRequest_GET(const string& _server, const string& _page, const string& _params = "");
};