#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    //CDinitial("D:\\");

    string input;
    char aux[256];

    cin.getline(aux,256);
    CDinitial("");
    CD("Music");

/*
///INPUT GRESIT - VEDEM!
    mv("fisier1.txt","/Music/fisier32.txt");
*/

   // remove("/home/lucian/newfile.txt");
///moved to...problem.
    //mv("");

    //Parcurgere("C:\\Users\\Laur\\Desktop", "*.txt");

/*    CDinitial("");
    cout<<"DUPA CD INITIAL\n";
    CD("Downloads");
    cout<<"DUPA PRIMUL ..\n";
    CD("..");
    cout<<"DUPa al doilea ..\n";*/

   // fileSize("Music");

    //ofstream fin("/home/lucian/fisier.txt");
    //fin<<"dsasdasda";
    //grep(aux);
    //ParcurgerePanaLaNivelulX("/home/lucian/","*.txt",1);

/*    string alfa[30]={"fisier.txt","fisier2.txt","fisier32.txt"};
    cat(alfa,3);*/
    string input2;
    char pro[255];

    while(1)
    {
        cin.getline(pro,255);
        input2=pro;
        CD(input2);
    }


    return 0;
}