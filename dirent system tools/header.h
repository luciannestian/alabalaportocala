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

#ifdef __linux
#define platforma 1
#elif __WIN32
#define platforma 0
#endif

//string slashkey;

void getPlatform();

void CDinitial(string  );

void CD(string );

void getDefaultPath();

void ls(DIR *);

void cat(string fisiere[100],int ,string,DIR *);

vector <string> listaFolder(DIR *directorOarecare,string numeDirector);

void  VerificareApartineFolder(vector<string>,string,string);

string numeDinLocatie(string nume);

bool esteNumeValid(string input,string pathFisier);

void Parcurgere(const char *,string);

void ParcurgerePanaLaNivelulX(const char *,string , int );
