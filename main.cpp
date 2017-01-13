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
    bool loop=1;
    while(loop==1)
    {
        cin.getline(cinput, 256);
        input = cinput;
        cmd = input.substr(0, input.find(' ') );
        //cout<<cmd<<"/n";
        command = input.substr(0, input.find(' '));
       // cout<<command;
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
            //cout << "ha";
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

            //cout << thisPath << "  " << newPath<<"\n";
            cp(thisPath,newPath);

            peekPathDefault(peek);
            cout << peek << ": ";
        }
        if(cmd.compare("mv")==0)
        {
           // cout << "ha";
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

          //  cout << thisPath << "  " << newPath<<"\n";
            mv(thisPath,newPath);

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
        else if(cmd.compare("find")==0) {
            //cout << "AM INTRAT IN FIND\n";
            char arg = cinput[6];

            string pattern = input.substr(input.find('"') + 1, input.rfind('"'));
            pattern.erase(pattern.end() - 1);

            if (arg == 'x')
            {
                char numar[20];
                int indiceNumar=0;
                string parcurs=cinput+8;
                int nivel;
                cout<<parcurs<<"\n";
                while(parcurs[indiceNumar]<='9' && parcurs[indiceNumar]>='0')
                {
                   // cout<<"se pune "<<parcurs[indiceNumar]<<"\n";
                    numar[indiceNumar]=parcurs[indiceNumar];
                    indiceNumar++;
                }

                numar[indiceNumar]=NULL;
                nivel=atoi(numar);
                //nivel--;
                cout << nivel<<" ";
                string path;
                peekPathDefault(path);
                ParcurgerePanaLaNivelulX(path.c_str(),pattern,nivel);

            }
            else {
                string path;
                peekPathDefault(path);
                Parcurgere(path.c_str(),pattern);
            }

            peekPathDefault(peek);
            cout << peek << ": ";
        }
        else if(strcmp(cinput,"exit")==0)
        {
            return 0;
        }
        else if(cmd.compare("cat")==0)
        {
            string fisiere[100];
            int indice=0;
            string dePrelucrat=input;
            string file;
            while(dePrelucrat.find('"')!=-1)
            {
                size_t poz1,poz2;
                poz1=dePrelucrat.find('"');
                string aux=dePrelucrat;
                dePrelucrat=aux.substr(poz1+1);
                aux=dePrelucrat;
                file=aux.substr(0,aux.find('"'));
                dePrelucrat=aux;

                cout<<dePrelucrat<<"  || "<<aux<<" "<<file<<"\n";
                fisiere[indice++]=file;
            }
            cat(fisiere,indice-1);

        }
    }

    return 0;
}
