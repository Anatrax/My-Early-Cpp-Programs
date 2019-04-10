/*
 * Menu- lists all c++ programs and their descriptions,
 * 	- reads from programList.txt
 * 	- runs program input by user
 */
#define WINVER 0x0500
#include <windows.h>
#include <fstream>
using namespace std;

int main()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    string queued;

    ifstream file("programList.txt");
    if (file.is_open())
    {
	string outputString;
	while (getline(file, outputString))
	{
	    cout << outputString << '\n';
	}
	file.close();
    }

    cout << endl
	 << "Which program would you like to run?" << endl;
    getline(cin, queued);

    for (int i = 0; i < (float)queued.length(); i++)
    {
	ip.ki.wScan = queued[i];
	ip.ki.wVk = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.wVk = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
    }

    ip.ki.wVk = 13; // Enter key
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}