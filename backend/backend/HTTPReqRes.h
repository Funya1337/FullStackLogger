#pragma once
#include <Windows.h>
#include <iostream>
#include <winhttp.h>
#pragma comment(lib, "Winhttp.lib")

using namespace std;

class HTTPReqRes
{
public:


	void sendMessageToBot()
	{
		HINTERNET hSession = WinHttpOpen(L"HTTP Example/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
		if (!hSession)
			cout << "no hSession" << endl;

		HINTERNET hConnect = WinHttpConnect(hSession, L"api.telegram.org", INTERNET_DEFAULT_HTTPS_PORT, 0);
		if (!hConnect)
			cout << "no connection" << endl;

		HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", L"{your http request}", NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);

		if (!hRequest)
			cout << "not make an request" << endl;

		WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0);
		WinHttpReceiveResponse(hRequest, NULL);
	}
};