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
    cout<<pathDefault<<"\n";
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

            //ls(directorDefault);
            // Parcurgere(pathDefault.c_str(),"*.ttf");
        }
    }

    else {
        if(input.length()>1)
        {
            string nouPath=pathDefault+slashkey+input;
            if(opendir(nouPath.c_str())!=0)
           {
            pathDefault+=slashkey;
            pathDefault+=input;
            directorDefault=opendir(pathDefault.c_str());
           // cout<<pathDefault<<"\n";
            }
            //ParcurgerePanaLaNivelulX(pathDefault.c_str(),"*.txt",1);
            //cout << directorDefault << "\n";
        }
    }
    //cout<<pathDefault;
    //ls(directorDefault);
}

void peekPathDefault(string &a)
{
    a = pathDefault;
}

void getDefaultPath()
{
    if(platforma==0)
        pathDefault="D:\\",directorDefault=opendir(pathDefault.c_str());
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

//void cp(char command[], DIR *dir)
//{
//    char myFile[256], newFile[256];
//    char *p;
//
//    strcpy(myFile, pathDefault.c_str());
//    strcpy(newFile, pathDefault.c_str());
//    myFile[3] = myFile[2];
//    newFile[3] = newFile[2]; //get C:\\, not C:\*
//
//    p = strchr(command, ' ');
//    strcat(myFile, p + 1);
//    p = strchr(myFile, ' ');
//    strcat(newFile, p + 1);
//    *p = 0;
//
//    ifstream source(myFile, ios::binary);
//    ofstream dest(newFile, ios::binary);
//
//    dest << source.rdbuf();
//
//    source.close();
//    dest.close();
//}

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


                //if(ent->d_type == DT_DIR)
                if(opendir(fullpath))
                {
                    Parcurgere(fullpath,input);
                }
            }
        }
        closedir(dir);

    }
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


                if(opendir(fullpath))
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

void fileSize(string filename)
{
    getPlatform();
    string New = pathDefault + slashkey + filename;
    cout << New;
    streampos begin,end;
    ifstream file(New.c_str(), ios::binary);
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

void lower(char pattern[])
{
    int i;
    for(i = 0; pattern[i]; ++i)
        if(pattern[i] >= 'A' && pattern[i] <= 'Z')
            pattern[i] += 32;
}

bool Extensie(char ext[])
{
    int i;
    for(i = 0; ext[i+1]; ++i)
        if(ext[i] == '.')
            return true;
    return false;
}

void grep(char command[])
{
    //cout << pathDefault;
    DIR *dir;
    dir = opendir(pathDefault.c_str());

    getPlatform();
//extract info
    char pattern[256];
    char *p;

    string myDir;
    p = strchr(command, '"');
    strcpy(pattern, p + 1);
    p = strchr(pattern, '"');
    *p = 0;

    dirent *e;
    //strcpy(myDir, pathDefault.c_str());
    char line[256];
    int n;
    bool found;

    if(dir != NULL)
    {
        if(strstr(command, "-n") && strstr(command, "-y"))
        {
            lower(pattern);
            e = readdir(dir);
            while(e != NULL)
            {
                if(Extensie(e->d_name))
                {
                    //myDir[len] = 0;
                    found = false;
                    n = 0;
                    myDir = pathDefault + slashkey + e->d_name;
                    ifstream f(myDir.c_str());
                    //if(f)
                        //cout << myDir << " ";
                    while(f)
                    {
                        f.getline(line, 256);
                        lower(line);
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
        else if(strstr(command, "-n"))
        {
            e = readdir(dir);
            while(e != NULL)
            {
                if(Extensie(e->d_name))
                {
                    found = false;
                    n = 0;
                    myDir = pathDefault + slashkey + e->d_name;
                    ifstream f(myDir.c_str());
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
            if(strstr(command, "-y"))
            {
                e = readdir(dir);
                lower(pattern);
                while(e != NULL)
                {
                    if(Extensie(e->d_name))
                    {
                        found = false;
                        myDir = pathDefault + slashkey + e->d_name;
                    ifstream f(myDir.c_str());
                        //if(f)
                            //cout << myDir << " ";
                        while(f)
                        {
                            f.getline(line, 256);
                            lower(line);
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
            else
            if(strstr(command, "-l"))
            {
                e = readdir(dir);
                while(e != NULL)
                {
                    if(Extensie(e->d_name))
                    {
                     //   myDir[len] = 0;
                        found = false;
                        myDir = pathDefault + slashkey + e->d_name;
                        ifstream f(myDir.c_str());
                        //if(f)
                            //cout << myDir << " ";
                        while(f)
                        {
                            f.getline(line, 256);
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
    closedir(dir);
    }
    else
    {
        perror("Unable to open dir.");
        return ;
    }

}

void cp(char numeFisier[],char numeNou[])
{
    //char myFile[256], newFile[256];
    getPlatform();
    string myFile,newFile;
//command
  //  char *p;
/*
    strcpy(myFile, pathDefault.c_str());
    strcpy(newFile, pathDefault.c_str())*/;
    myFile=pathDefault+slashkey+numeFisier;
    newFile=pathDefault+slashkey+numeNou;
    cout << myFile << "  " << newFile;

//    if(platforma==0) {
  //      myFile[3] = myFile[2];
    //    newFile[3] = newFile[2]; //get C:\\, not C:
      //  }


 /*   p = strchr(command, ' ');
    strcat(myFile, p + 1);
    p = strchr(myFile, ' ');
    strcat(newFile, p + 1);
    *p = 0;
 */
//    cout<<myFile<<" APOI NEW FILE ";
  //  cout<<opendir(newFile.c_str())<<" ";
    //cout<<newFile<<"\n";
    ifstream source(myFile.c_str(), ios::binary);
    ofstream dest(newFile.c_str(), ios::binary);
    //cout<<"citire\n";
    //cout<<source.rdbuf();

    dest << source.rdbuf();

    source.close();
    dest.close();
}


void mv(char numeFisier[],char numeNou[])
{
    //char myFile[256], newFile[256];
    getPlatform();
    string myFile,newFile;
//command
    //  char *p;
/*
    strcpy(myFile, pathDefault.c_str());
    strcpy(newFile, pathDefault.c_str())*/;
    myFile=pathDefault+slashkey+numeFisier;
    newFile=pathDefault+slashkey+numeNou;
    cout<<"cp\n";
    cout<<myFile<<" ";
    cout<<newFile<<"\n";
    if(platforma==0) {

        myFile[3] = myFile[2];

        newFile[3] = newFile[2]; //get C:\\, not C:
    }

    cout<<myFile<<" APOI NEW FILE ";
    cout<<opendir(newFile.c_str())<<" ";
    cout<<newFile<<"\n";
    ifstream source(myFile.c_str(), ios::binary);
    ofstream dest(newFile.c_str(), ios::binary);
    cout<<"citire\n";
    //cout<<source.rdbuf();

    dest << source.rdbuf();

    source.close();

    string deleteFile(myFile);

    remove(deleteFile.c_str());

    //dest.close();

    cout<<"\n DE STERS "<<deleteFile<<"\n";

    dest.close();
}
