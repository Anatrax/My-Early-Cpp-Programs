/*
 * Creates new c++ program, add title and description to programList.txt
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string title;
    string description;
    ofstream file;
    ostringstream ss;

    if(argc <= 3)
    {
        if(argv[0])
            cout << "Usage: " << argv[0] << " <program_name> <desciption> <of> <new> <program>" << endl;
        else
            cout << "Usage: " << argv[0] << " <program_name> <desciption> <of> <new> <program>" << endl;
        exit(1);
    }

    title = argv[1];
    for(int i = 2; i < argc; i++)
    {
            description += " ";
            description += argv[i];
    }

    file.open("programList.txt", ios::app);
    file << title << "- " << description << endl;
    file.close();

    title += ".cpp";
    const char *filename = title.c_str();

    file.open(filename);
    file << "/*\n* "
	 << description << "\n*/\n#include <iostream>\n\nint main()\n{\n\tcout << \"Hello World\" << endl;\n}\n";
    file.close();

    cout << "C++ Program Created: " << title << "- " << description << endl;
    return 0;
}
