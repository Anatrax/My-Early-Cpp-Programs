/*
 * HideAndSeek- hides a file in a picture
 */
#define WINVER 0x0500
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int text(char letters[]){
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.dwFlags = KEYEVENTF_UNICODE;

	float numberOfLetters = strlen(letters);

	for(int i = 0; i < numberOfLetters; i++){
		ip.ki.wScan = letters[i];
		ip.ki.wVk = 0;
		SendInput(1, &ip, sizeof(INPUT));
		ip.ki.wVk = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		SendInput(1, &ip, sizeof(INPUT));
	}
	return 0;
}

int specialCharacters(int specialChar){
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	ip.ki.wVk = specialChar; // virtual-key code in decimal format
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		if (argv[0])
			cout << "Usage: " << argv[0] << " <image.jpg> + <filename.rar> <finalimage.jpg>" << '\n';
		else
			cout << "Usage: <program name> <image.jpg> + <filename.rar> <finalimage.jpg>" << '\n';
 
		exit(1);
	}

	text("copy /b ");
	text(argv[1]);
	text(" + ");
	text(argv[2]);
	text(" ");
	text(argv[3]);
	specialCharacters(13); // 13 is Enter key

	return 0;
}