#include <iostream>
#include <fstream>
#include <dirent.h>
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

void peekPathDefault(string &a);

void fileSize(string );

void cp(char numeFisier[],char numeNou[]);

void grep(char command []);

void mv(char numeFisier[],char numeNou[]);

//string slashkey;

void getPlatform();

void CDinitial(string);

void CD(string);

void getDefaultPath();

void ls(DIR *);

void cat(string fisiere[100], int, string, DIR *);

vector <string> listaFolder(DIR *directorOarecare, string numeDirector);

void  VerificareApartineFolder(vector<string>, string, string);

string numeDinLocatie(string nume);

bool esteNumeValid(string input, string pathFisier);

void Parcurgere(const char *, string);

void ParcurgerePanaLaNivelulX(const char *, string, int);
