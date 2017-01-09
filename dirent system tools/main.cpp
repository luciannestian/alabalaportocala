#include "header.h"


int main() {
    ofstream fil("director1\\fili.mp3");
    fil<<"11";
    ls(opendir("C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1"));
    //cout<<"\n sfarsit ls \n";

    string a[100]={"file2","are","file1"};
  /*  cout<<a->length()<<"\n";
    for(int i=0;i<a->length();i++)
        cout<<a[i].length()<< " ";*/
   // cat(a,3);

    DIR *directorul_curent=opendir("C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1");

   ///primele 2 elemente din vector sunt . si ..
    vector <string> x=listaFolder(directorul_curent,"C:\\Users\\aditi\\OneDrive\\Documents\\CLion Projects\\dirent system tools\\director1");

    /*for(int i=0;i<x.size();i++)
        cout<<x[i]<<"\n";
    *///Deschidere(x);

/*    for(int i=found+1;i<h.size();i++)
        cout<<h[i];*/

    Deschidere(x);
    //int alfa=x[2].find(".");
   // cout<<x[2].substr(alfa);

    return 0;
}