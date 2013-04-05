#ifndef MYLIB_H
#define MYLIB_H
#include "stdafx.h"
#include <iostream>
#include <string>
char* resize(char* cnarray);
void parsearray(char* cnarray);
void delspace(char* input);
double power(double base, double power);
std::string getinput();
void AddTermChar(char* cstring);
int GetTermLoc(char* cstring);
#pragma warning(disable:4996)
#endif