#include "SecureNetwork.h"
SecureNetwork::SecureNetwork()
{
}

SecureNetwork::~SecureNetwork()
{
}

string SecureNetwork::SendHTTPSRequest_GET(const string& _server, const string& _page, const string& _params)
{
	string answer = "";

	// initialize WinInet
	HINTERNET hInternet = ::InternetOpen(TEXT("WinInet Test"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hInternet != NULL)
	{
		// open HTTP session
		wstring _serverw = std::wstring(_server.begin(), _server.end());
		HINTERNET hConnect = ::InternetConnect(hInternet, _serverw.c_str(), INTERNET_DEFAULT_HTTPS_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
		if (hConnect != NULL)
		{
			string request = _page +
				(_params.empty() ? "" : ("?" + _params));

			// open request
			wstring requestw = std::wstring(request.begin(), request.end());
			HINTERNET hRequest = ::HttpOpenRequest(hConnect, L"GET", requestw.c_str(), NULL, NULL, 0, INTERNET_FLAG_SECURE, 1);
			if (hRequest != NULL)
			{
				// send request
				BOOL isSend = ::HttpSendRequest(hRequest, NULL, 0, NULL, 0);

				if (isSend)
				{
					while (true)
					{
						char szData[BUFFERSIZE];
						// reading data
						DWORD dwByteRead = 0;
						BOOL isRead = ::InternetReadFile(hRequest, szData, sizeof(szData) - 1, &dwByteRead);

						// break cycle if error or end
						if (isRead == FALSE || dwByteRead == 0)
							break;

						// saving result
						szData[dwByteRead] = 0;
						answer = answer + szData;
					}
				}

				// close request
				::InternetCloseHandle(hRequest);
			}
			// close session
			::InternetCloseHandle(hConnect);
		}
		// close WinInet
		::InternetCloseHandle(hInternet);
	}


	return answer;
}