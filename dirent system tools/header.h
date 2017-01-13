#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string>
#include <typeinfo>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;


#ifdef __linux
#define platforma 1
#elif __WIN32
#define platforma 0
#endif


void fileSize(string );

void cp(char [],char []);

void grep();

void mv(char [],char []);

//string slashkey;

void getPlatform();

void CDinitial(string);

void CD(string);

void getDefaultPath();

void ls(DIR *);

void cat(string fisiere[100], int);

vector <string> listaFolder(DIR *directorOarecare, string numeDirector);

void  VerificareApartineFolder(vector<string>, string, string);

string numeDinLocatie(string nume);

bool esteNumeValid(string input, string pathFisier);

void Parcurgere(const char *, string);

void ParcurgerePanaLaNivelulX(const char *, string, int);

void grep(char []);

void peekPathDefault(string &);