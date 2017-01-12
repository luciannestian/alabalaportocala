#ifndef DIRENT_SYSTEM_TOOLS_HEADER_H
#define DIRENT_SYSTEM_TOOLS_HEADER_H
#endif //DIRENT_SYSTEM_TOOLS_HEADER_H

#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <vector>
#include <cstring>

using namespace std;

//string backslash;

/*
#ifdef OS_WINDOWS
    backslash="\\";
#else
    string backslash="/";
//define it for a Unix machine
#endif
*/

//DIR *directorul_curent;

void ls(DIR *);

void cat(string fisiere[100],int );

vector <string> listaFolder(DIR *directorOarecare,string numeDirector);

void  VerificareApartineFolder(vector<string>,string,string);

string numeDinLocatie(string nume);

bool esteNumeValid(string input,string pathFisier);

void Parcurgere(char *,string);

void ParcurgerePanaLaNivelulX(char *,string , int );

