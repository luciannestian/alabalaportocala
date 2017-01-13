
#include "header.h"
#define arraysize(ar)  (sizeof(ar) / sizeof(ar[0]))


string pathDefault;
string slashkey;
DIR *directorDefault;

void getPlatform()
{
    if(platforma==0)
        slashkey="\\";
    else slashkey="/";
}


void CDinitial(string path)
{
    getDefaultPath();
    if(path.empty()!=1 )
    {
        pathDefault=path;
        if(opendir(path.c_str()))
            directorDefault=opendir(path.c_str());
    }
    //cout<<pathDefault<<"\n";
   // ls(directorDefault);
/*    string x="*.flac";
    Parcurgere(pathDefault.c_str(),x);*/
}

void CD(string input)
{
    getPlatform();
    //CDinitial("");

    if(input.compare("..")==0)
    {
        //un director inapoi
//        string
        if(platforma==1)
            pathDefault.erase(pathDefault.length()-1);

        int found =pathDefault.rfind(slashkey);
        // cout<<"path inainte de prelucrare   "<<pathDefault;
        //  cout<<" || found "<<found<<" || ";

        // cout<<pathDefault.length()<<" ";
        //cout<<found<<" ";
        //cout<<platforma<<" ";
        //cout<< ""<<pathDefault;
        if(found!=-1) {
            //cout<<pathDefault<<" ";
            string numenou = pathDefault.substr(0, found);
            //cout <<"numenou "<< numenou<<"\n";
            pathDefault=numenou;
            numenou+=slashkey;
            // cout<<"numenou  "<<numenou<<"\n";
            directorDefault=opendir(numenou.c_str());

            ls(directorDefault);
            // Parcurgere(pathDefault.c_str(),"*.ttf");
        }
    }

    else {
        if(input.length()>1)
        {
            pathDefault+=slashkey;
            pathDefault+=input;
            directorDefault=opendir(pathDefault.c_str());
           // cout<<pathDefault<<"\n";
            // ls(directorDefault);
            ParcurgerePanaLaNivelulX(pathDefault.c_str(),"*.txt",1);
        }
    }
}

void getDefaultPath()
{
    if(platforma==0)
        pathDefault="C:\\director1",directorDefault=opendir(pathDefault.c_str());
    else pathDefault="/home/lucian",directorDefault=opendir(pathDefault.c_str());
}

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



void cat(string fisiere[100],int nr_fisiere,string numeDirectorCurent,DIR *directorDefault) {

    getPlatform();
/*    DIR *directorul_curent = opendir(
            "C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1");*/
    int indice_fisier;

    //dirent *end;
    DIR *p = directorDefault;

    //output trebuie sa fie directorul curent din cd

    string pathFisierRezultat=pathDefault+slashkey+"fisier rezultat.txt";

    ofstream output(pathFisierRezultat.c_str());
    //cout<<pathFisierRezultat<<" ";

    //cout<<p<<" "<<"pasul "<<indice_fisier<<"\n";
    dirent *end;
    // dir = opendir ("C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1");
    if ( p != NULL) {
        end= readdir (p);
        cout<<end->d_name<<" ";
        while (end  != NULL) {
            for (indice_fisier = 0; indice_fisier < nr_fisiere; indice_fisier++) {
                //cout<<fisiere[indice_fisier]<<" ";
                if(strcmp(fisiere[indice_fisier].c_str(),end->d_name)==0)
                {
                    cout<<"am gasit "<<end->d_name<<"\n";
                    string locatieFisierGasit;

                    locatieFisierGasit=numeDirectorCurent;
                    locatieFisierGasit+=slashkey;
                    locatieFisierGasit+=end->d_name;
                    cout<<locatieFisierGasit<<"\n";
                    ifstream fisierGasit1;//(locatieFisierGasit);
                    fisierGasit1.open(locatieFisierGasit);

                    string x;

                    if(fisierGasit1.is_open()==true)
                        while(fisierGasit1.eof()==false)
                        {
                            char h[255];
                            fisierGasit1.getline(h,255);
                            x+=h;
                            x+="\n";
                        }

                    fisierGasit1.close();
                    cout<< '|';
                    cout<<x<<" ";

                    //x.erase(x.end()-1);
                    //windows
                    //ultimul caracter face probleme
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
   // Parcurgere(numeDirectorCurent.c_str(),"*.txt");
    output.close();
}


vector <string> listaFolder(DIR *directorOarecare,string numeDirector)
{
    //ls
    // string slashkey;///depinde de platforma
    vector <string> lista;
    //numeDirector.erase(numeDirector.end()-1);
    dirent *end;
    int indiceFisier=0;

    if ( directorOarecare != NULL) {
        end= readdir (directorOarecare);
        while (end  != NULL) {
            lista.push_back(numeDirector);
            // strcat(lista[indiceFisier],slashKey);
            lista[indiceFisier]+=slashkey;
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
    getPlatform();
    size_t found=nume.rfind(slashkey.c_str());
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


void Parcurgere(const char *path,string input)
{
    getPlatform();
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if ((strcmp(ent->d_name, "..") != 0) && (strcmp(ent->d_name, ".") != 0)) {

                // printf("%s", ent->d_name);

                char fullpath[300];
                strcpy(fullpath, path);
                strcat(fullpath, slashkey.c_str());

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


void ParcurgerePanaLaNivelulX(const char *path,string input,int nivelInput)
{
    getPlatform();
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if ((strcmp(ent->d_name, "..") != 0) && (strcmp(ent->d_name, ".") != 0)) {

                // printf("%s", ent->d_name);

                char fullpath[200];

                strcpy(fullpath, path);
                strcat(fullpath, slashkey.c_str());
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