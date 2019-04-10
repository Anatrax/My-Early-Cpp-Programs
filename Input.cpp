/*
 * Input- outputs user input [uses getInput()]
 */
#include <iostream>
using namespace std;

int main()
{
	string input;
	cout << "User Input:" << endl;
	getline(cin, input);
	cout << "Output: "<< input << endl;
	return 0;
}