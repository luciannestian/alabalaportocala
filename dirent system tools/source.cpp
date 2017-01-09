#include "header.h"
#define arraysize(ar)  (sizeof(ar) / sizeof(ar[0]))

void ls(DIR *dir)
{
    //ls
    dirent *end;
   // dir = opendir ("C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1");
    if ( dir != NULL) {
        end= readdir (dir);
        while (end  != NULL) {
            cout<<end->d_name<<"\n";
            end = readdir(dir);
        }
        closedir (dir);
    }
    else {
        perror ("");
        return ;
    }
}


void cat(string fisiere[100],int nr_fisiere) {
    DIR *directorul_curent = opendir(
            "C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1");
    int indice_fisier;
    string numeDirectorCurent="C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1";
    //dirent *end;
    DIR *p = directorul_curent;
    ofstream output("C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1\\fisier_rezultat");
    p = directorul_curent;
    //cout<<p<<" "<<"pasul "<<indice_fisier<<"\n";
    dirent *end;
    // dir = opendir ("C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1");
    if ( p != NULL) {
            end= readdir (p);
            while (end  != NULL) {
                for (indice_fisier = 0; indice_fisier < nr_fisiere; indice_fisier++) {
                    if(fisiere[indice_fisier]==end->d_name)
                    {
                        cout<<"am gasit "<<end->d_name<<"\n";
                        string locatieFisierGasit;

                        locatieFisierGasit=numeDirectorCurent;
                        locatieFisierGasit+='\\';
                        locatieFisierGasit+=end->d_name;
                        ifstream fisierGasit1(locatieFisierGasit);

                        string x;
                        while(fisierGasit1.eof()==false)
                        {
                            x+=fisierGasit1.get();
                        }
                        x.erase(x.end()-1);//ultimul caracter face probleme
                        output<<x;

                        cout<<"se da citire din el "<<x<<"\n";
                    }
                }
                end = readdir(p);
            }
            closedir (p);
        }
        else {
            perror ("");
        }

    output.close();

}



vector <string> listaFolder(DIR *directorOarecare,string numeDirector)
{
    //ls
    string slashKey="\\";///depinde de platforma

    vector <string> lista;
    //numeDirector.erase(numeDirector.end()-1);
    dirent *end;
    int indiceFisier=0;

    if ( directorOarecare != NULL) {
        end= readdir (directorOarecare);
        while (end  != NULL) {
            lista.push_back(numeDirector);
           // strcat(lista[indiceFisier],slashKey);
            lista[indiceFisier]+=slashKey;
            string x=end->d_name;

            lista[indiceFisier++]+=x;
            //strcat(lista[indiceFisier],end->d_name);
            end = readdir(directorOarecare);
        }
        closedir (directorOarecare);
    }

    return lista;
}

string numeDinLocatie(string nume)
{
    string x;
    //"C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1";
    size_t found=nume.rfind("\\");
    string nou=nume.substr(found+1);
    // cout<<nou;
    return nou;
}

bool esteNumeValid(string input,string pathFisier)
{
    string numeFisier=numeDinLocatie(pathFisier);
    if(input==numeFisier)
        return 1;
    int existaSteluta =input.find("*");
    if(existaSteluta==-1)
        return 0;
    if(existaSteluta==0)
    {
        string inputFaraSteluta;

    }
    if(existaSteluta==input.length())
    {
        string inputFaraSteluta;
    }
}

void Deschidere(vector <string> listaFisiere)
{
    DIR *director;
    for(int i=0;i<listaFisiere.size();i++)
    {
        char * sir = new char[listaFisiere[i].length() + 1];
        strcpy(sir,listaFisiere[i].c_str());
        cout<<sir<<" ";
        cout<<numeDinLocatie(listaFisiere[i])<<"\n";
    }

  // director=opendir(listaFisiere[0]);
}