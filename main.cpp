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

bool Extensie(char ext[])
{
    int i;
    for(i = 0; ext[i+1]; ++i)
        if(ext[i] == '.')
            return true;
    return false;
}

void grep(DIR *dir)
{
//extract info
    char pattern[256], subfunc[256];
    //char filename[256];
    char *p;

//pattern && subfuntion && filename
    p = strchr(command, '-');
    strcpy(subfunc, p);
    p = strchr(subfunc, ' ');
    *p = 0;

    p = strchr(command, '"');
    strcpy(pattern, p + 1);
    p = strchr(pattern, '"');
    //strcpy(filename, p + 2);
    *p = 0;

    dirent *e;
    char myDir[256];
    strcpy(myDir, dir->dd_name);
    myDir[3] = myDir[2]; // copy '\' to '*'
    int len = strlen(myDir);
    char line[256];
    int n;
    bool found;

    if(dir != NULL)
    {
        if(strcmp(subfunc, "-n") == 0)
        {
            e = readdir(dir);
            while(e != NULL)
            {
                if(Extensie(e->d_name))
                {
                    myDir[len] = 0;
                    found = false;
                    n = 0;
                    strcat(myDir, e->d_name);
                    myDir[3] = myDir[2];
                    ifstream f(myDir);
                    //if(f)
                        //cout << myDir << " ";
                    while(f)
                    {
                        f.getline(line, 256);
                        if(strstr(line, pattern))
                        {
                            cout << n << "\n";
                            found = true;
                        }
                    ++n;
                    }
                    if(found == true)
                        cout << e->d_name << "\n";
                }
            e = readdir(dir);
            }
        }
        else
            if(strcmp(subfunc, "-y") == 0)
        {
            e = readdir(dir);
            while(e != NULL)
            {
                if(Extensie(e->d_name))
                {
                    strlwr(pattern);
                    myDir[len] = 0;
                    found = false;
                    strcat(myDir, e->d_name);
                    myDir[3] = myDir[2];
                    ifstream f(myDir);
                    //if(f)
                        //cout << myDir << " ";
                    while(f)
                    {
                        f.getline(line, 256);
                        strlwr(line);
                        if(strstr(line, pattern))
                        {
                            found = true;
                        }
                    }
                    if(found == true)
                        cout << e->d_name << "\n";
                }
            e = readdir(dir);
            }
        }

    }
    else
    {
        perror("Unable to open dir.");
        return ;
    }

}

int main()
{
    DIR *dir;
    dir = opendir("D:\\");

    cin.getline(command, 256);

    grep(dir);

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
