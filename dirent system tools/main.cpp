#include "header.h"


int main() {
    ofstream fil("director1\\fili.mp3");
    fil<<"11";
   // ls(opendir("C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent iara\\director1"));
    //cout<<"\n sfarsit ls \n";

    //string a[100]={"file2","are","file1"};
    /*  cout<<a->length()<<"\n";
      for(int i=0;i<a->length();i++)
          cout<<a[i].length()<< " ";*/
    // cat(a,3);

    DIR *directorul_curent=opendir("C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent iara\\director1");
    string input="*.mp3";
//    Parcurgere("C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent iara",input);
    //char *pathMare="C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent iara\\director1";
   // ParcurgerePanaLaNivelulX(pathMare,input,0);

    //cout<<esteNumeValid(input,"C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent iara.mp2");


    ///primele 2 elemente din vector sunt . si ..
    vector <string> x=listaFolder(directorul_curent,"C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent iara\\director1");

/*    for(int i=0;i<x.size();i++)
        cout<<x[i]<<"\n";*/
   // VerificareApartineFolder(x,"salami","*.txt");

    /*///Deschidere(x);

/*    for(int i=found+1;i<h.size();i++)
        cout<<h[i];*/

    //Deschidere(x);

    //int alfa=x[2].find(".");
    // cout<<x[2].substr(alfa);
/*
    string numeFisier="\\salam\\nume123.mp213";
    numeFisier=numeDinLocatie(numeFisier);

    int pozitie=numeFisier.find(".");

    string fisierFaraExtensie=numeFisier.substr(0,pozitie);

    cout<<fisierFaraExtensie;
*/

/*

    string newa="*.txt";
    string b="C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent iara\\director1\\file1.txt";
    cout<<'\n';
    cout<<esteNumeValid(newa,b);
*/
/*
    string xa;
    getPlatform(xa);
    cout << xa;
*/


    string numedirectorcurent="C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent iara\\director1";
/*
    int found = numedirectorcurent.rfind("\\");
    if(found) {
        string numenou = numedirectorcurent.substr(0,found);
        cout << numenou;
    }*/
    CDinitial("C:\\");
   // CD("..");
    //cout<<"\n\n\CD 2 \n\n";
    cout<<"CD DOWNLOADS\n";


    string lista[100]={"file1.txt","file2.txt"};
    CD("..");
    CD("..");
    cat(lista,2,"C:\\director1",opendir("C:\\"));
   // cat(lista,2,"C:\\director1",opendir("C:\\director1"));

   /* ifstream fin;
    fin.open("/home/lucian/Documents/text1.txt");

    char lalala[255];
    fin.getline(lalala,255);
    fin.getline(lalala,255);
    cout<<"\n||"<<lalala<<" ||";*/

    return 0;
}