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

    //output trebuie sa fie directorul curent din cd

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
    //string x;
    //"C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1";

    ///LINUX ARE ALT PATH

    size_t found=nume.rfind("\\");
    string nou=nume.substr(found+1);
    // cout<<nou;
    return nou;
}

bool esteNumeValid(string input,string pathFisier)
{
    string numeFisier=numeDinLocatie(pathFisier);
   // cout<<"nume fisier:"<<numeFisier<<"\n";
    if(input==numeFisier)
        return 1;
    int existaSteluta =input.find("*");
    //cout<<existaSteluta<<"\n";

    if(existaSteluta==-1)
        return 0;
    if(existaSteluta==0)
    {
        string extensiaInput=input.substr(1);
        //cout<<extensiaInput<<" ";
        int pozitie=pathFisier.rfind(".");
        if(pozitie>pathFisier.length()-1)
            return 0;

        string extensiaFisier=pathFisier.substr(pozitie);
        //cout<<extensiaFisier<<"\n";
        if(extensiaFisier.compare(extensiaInput)==0)
            return 1;
        return 0;
    }
    if(existaSteluta==input.length()-1)
    {
        string inputFaraExtensie=input.substr(0,input.length()-2);

        int pozitie=numeFisier.find(".");

        string fisierFaraExtensie=numeFisier.substr(0,pozitie);
        if(fisierFaraExtensie.compare(inputFaraExtensie)==0)
            return 1;
        return 0;
    }

    return 1;
}



void VerificareApartineFolder(vector <string> listaFisiereDintrunFolder,string numeDirector,string input)
{
    //DIR *director;
    for(int i=0;i<listaFisiereDintrunFolder.size();i++)
    {
/*        char * sir = new char[listaFisiereDintrunFolder[i].length() + 1];
        strcpy(sir,listaFisiereDintrunFolder[i].c_str());*/
       if(esteNumeValid(input,listaFisiereDintrunFolder[i])==1)
           cout<<numeDirector<<"\\"<<listaFisiereDintrunFolder[i]<<"\n";///LINUX NU ARE "\\"
    }

    // director=opendir(listaFisiere[0]);
}

//daca e folder intru in el si returnez lista fisierelor apoi comparez cu ala de la input
//daca nu merem mai departe , return 0
/*

void Parcurgere(string path)
{
    DIR* dir=opendir(path.c_str());
    if(dir==NULL) return;
    else
    {
        dirent *end=readdir(dir);
        vector <string> lista=listaFolder(dir,path);


    }

}

*/


void Parcurgere(char *path,string input)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if ((strcmp(ent->d_name, "..") != 0) && (strcmp(ent->d_name, ".") != 0)) {

               // printf("%s", ent->d_name);

                char fullpath[200];

                strcpy(fullpath, path);
                strcat(fullpath, "\\");
                strcat(fullpath, ent->d_name);
                string h=fullpath;
               // cout<<h<<"\n";
                if(esteNumeValid(input,h)==1)
                    printf("%s",fullpath),printf("\n");


                if(ent->d_type == DT_DIR)
                {
                    Parcurgere(fullpath,input);
                }
            }
        }
        closedir(dir);

    }
}


void ParcurgerePanaLaNivelulX(char *path,string input,int nivelInput)
{

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if ((strcmp(ent->d_name, "..") != 0) && (strcmp(ent->d_name, ".") != 0)) {

                // printf("%s", ent->d_name);

                char fullpath[200];

                strcpy(fullpath, path);
                strcat(fullpath, "\\");
                strcat(fullpath, ent->d_name);
                string h=fullpath;
                // cout<<h<<"\n";
                if(esteNumeValid(input,h)==1)
                    printf("%s",fullpath),printf("\n");


                if(ent->d_type == DT_DIR)
                {
                    if(nivelInput>0)
                    {
                        ParcurgerePanaLaNivelulX(fullpath,input,nivelInput-1);
                       // nivelInput++;
                    }

                }
            }
        }
        closedir(dir);

    }
}