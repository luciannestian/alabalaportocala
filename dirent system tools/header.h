#ifndef DIRENT_SYSTEM_TOOLS_HEADER_H
#define DIRENT_SYSTEM_TOOLS_HEADER_H

#endif //DIRENT_SYSTEM_TOOLS_HEADER_H

#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

//DIR *directorul_curent;

void ls(DIR *);

void cat(string fisiere[100],int );

