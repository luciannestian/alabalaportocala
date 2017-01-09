#include <iostream>
#include <fstream>

using namespace std;

void copyFile()
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

int main()
{
    copyFile();

    return 0;
}
