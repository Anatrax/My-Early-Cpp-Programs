/*
 * A program that outputs its own source code
 *	- can output contents of different file if specified
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	string outputString;

	if (argc <= 1) argv[1] = "Quine.cpp"; // "Quine.cpp" if no other file specified

	ifstream file(argv[1]);
	if (file.is_open())
	{
		while (getline (file, outputString))
		{
			cout << outputString << '\n';
		}
		file.close();
	}
}