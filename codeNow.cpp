/*
 * codeNow: runs commands from a specified file
 *   - Settings[.txt] (default): initializes CLI programming environment
 */
#define WINVER 0x0500
#include <windows.h>
#include <fstream>
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
	ip.ki.wVk = 13; // Enter key
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	cout << "Running_" << letters << endl;
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc <= 1) argv[1] = "Settings.txt";	// "Settings.txt" if no other file specified

	ifstream file(argv[1]);				// sets the input file to argv[1]

	if(!file){
		cout << "Could not open file:" << argv[1] << endl;
		exit(1);
	}

	while(file && getline(file, out)){		// while file exists and next line recieved
		string out;				// output string
		if(out.length() == 0)continue;		// skip blank lines
		text((char *)out.c_str());
	}

	file.close();
}