#include <iostream>
#include <fstream>

using namespace std;

void cp()
{
    char fpath[256], npath[256];

    cout << "File Path: "; cin >> fpath;
    cout << "New Path (+ old/new name): "; cin >> npath;

    ifstream source(fpath, ios::binary);
    ofstream dest(npath, ios::binary);

    dest << source.rdbuf();

    source.close();
    dest.close();
}

void fileSize()
{
    streampos begin,end;
    ifstream file("D:\myImage.png", ios::binary);
    if(file.is_open())
    {
        begin = file.tellg();
        file.seekg (0, ios::end);
        end = file.tellg();
        cout << "size is: " << (end-begin) << " bytes.\n";
    }
    else
        cout << "Cannot open this file.";
    file.close();

}

void mv()
{
    ;
}

int main()
{
    fileSize();

    return 0;
}
