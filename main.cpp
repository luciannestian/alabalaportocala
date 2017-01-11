#include <iostream>
#include <fstream>
#include <cstring>
#include <dirent.h>

using namespace std;

void fileSize();
void recCommand(char command[]);
void cp();
void grep();

    char command[256];

void Find(DIR *dir)
{
    dirent *e;

    char aux[256];

    if(dir != NULL)
    {
        e = readdir(dir);
        while(e != NULL)
        {
            cout << e->d_name << "  ";
            if(strcmp(e->d_name, "myText.txt") == 0)
            {
                string path(dir->dd_name);
                cout << path;
                cout << "\n";
                ifstream f;
                f.open("myText.txt");
                if(f.is_open())
                {
                    while(!f.eof())
                    {
                        f.getline(aux, 256);
                        cout << aux << " ";
                    }
                }
                else ;
                while(f)
                {
                    f.getline(aux, 256);
                    cout << "\n" << aux << "\n";
                }
            }
            e = readdir(dir);
        }
    }
    else ;

}

void grep()
{
    char *p;
    p = strchr(command, '"');
    char myString[256], subFunc[256];
    strcpy(myString, p + 1);
    p = strchr(myString, '"');
    *p = 0;
    p = strchr(command, '-');
    strcpy(subFunc, p);
    p = strchr(subFunc, ' ');
    *p = 0;

    ifstream myFile("D:\\myText.txt", ios::binary);

    unsigned int n = 0;
    char read[256];

    if(!myFile)
        cout << "File not found.";
    else
    {
        bool stringFound = false;
        if(strcmp(subFunc, "-n") == 0)
            {
                while(myFile)
                {
                    myFile.getline(read, 256);
                    if(strstr(read, myString))
                    {
                        stringFound = true;
                        cout << n << "\n";
                    }
                }
                ++n;
            }
        else
            if(strcmp(subFunc, "-y") == 0)
            {
                strlwr(myString);
                while(myFile)
                {
                    myFile.getline(read, 256);
                    strlwr(read);
                    if(strstr(read, myString))
                    {
                        stringFound = true;
                    }
                }
            }
            else
                if(strcmp(subFunc, "-l") == 0)
                {
                    while(myFile)
                    {
                        myFile.getline(read, 256);
                        if(strstr(read, myString))
                        {
                            stringFound = true;
                        }
                    }
                }
        if(stringFound == true)
            cout << "myText.txt";
        else
            cout << "String not found.";
    }

}


int main()
{

    DIR *dir;
/*
    cout << "\nDirectory C\n";
    dir = opendir("C:\\");
    Find(dir, d);
*/
    cout << "\n\nDirectory D\n";
    dir = opendir("D:\\");
    Find(dir);
    //Find("D:\\");

    /*
    cin.getline(command, 256);

    char *p, myFunc[256];
    strcpy(myFunc, command);

    int i = 0;
    while(myFunc[i] != ' ')
        ++i;
    myFunc[i] = 0;

    if(strcmp(myFunc, "grep") == 0)
        grep();
    else ;
    */

    return 0;
}
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

void recCommand(char command[])
{
    char var1[256], var2[256], var3[256];

    char *p;
    strcpy(var1, command);
    p = strchr(var1, ' ');
    strcpy(var2, p+2);
    *p = 0;
    p = strchr(var2, '"');
    *p = 0;

    if(strcmp(var1, "cp") == 0 )
        cp();
    else
        if(strcmp(var1, "sizeof") == 0)
            fileSize();
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
        cout << "Size of file: " << (end-begin) << " bytes.\n";
    }
    else
        cout << "Cannot open this file.";
    file.close();

}
