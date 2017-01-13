#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    string input;
    char cinput[256];
    cin.getline(cinput, 256);
    input = cinput;
    CDinitial(input);
        string command;
        string path;
        string peek;
        string cmd;

    while(1)
    {
        cin.getline(cinput, 256);
        input = cinput;
        cmd = input.substr(0, input.find(' ') );
        //cout<<cmd<<"/n";
        command = input.substr(0, input.find(' '));
        if(command.compare("cd") == 0)
        {
            path = input.substr(input.find(' ')+1, input.size());
            CD(path);
            peekPathDefault(peek);
            cout << peek << ": ";
        }
        else
            if(input.compare("ls") == 0)
            {
                peekPathDefault(peek);
                ls((opendir(peek.c_str())));
                cout << peek << ": ";
            }

            else
                if(cmd.compare("cp") == 0)
                {
                    cout << "ha";
                    char thisPath[256], newPath[256];
                    char *p;

                    p = strchr(cinput, '"');
                    cout << p;
                    strcpy(thisPath, p + 1);
                    p = strchr(thisPath, '"');
                    strcpy(newPath, p + 3);
                    *p = 0;
                    p = strchr(newPath, '"');
                    *p = 0;

                    cout << thisPath << "  " << newPath<<"\n";
                    cp(thisPath,newPath);

                    peekPathDefault(peek);
                    cout << peek << ": ";
                }
                else
                    if(cmd.compare("grep") == 0)
                    {
                        grep(cinput);
                        peekPathDefault(peek);
                        cout << peek << ": ";
                    }
                else
                    if(cmd.compare("filesize")==0)
                {
                    string h=cinput+9;
                    fileSize(h);
                     peekPathDefault(peek);
                        cout << peek << ": ";

                }
                else if(cmd.compare("find"))
                {
                    ;
                }


    }



    return 0;
}
