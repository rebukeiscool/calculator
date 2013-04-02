#ifndef OPERATION_H
#define OPERATION_H
#include <string>
void solveset(char* input, int startset, int* endset);
void DoParenth(char* input, int startset, int* endset);
void DoExp(char* input, int startset, int* endset);
void DoMultiDiv(char* input, int startset, int* endset);
void DoPlusMinus(char* input, int startset, int* endset);
void getTerm(char* input,int counter,double* term);
void DoParenth(char* input,int startset,int* endset);
void HandleParenth(char* input,int openpar,int* closepar);
void AnsReplace(char* input,int beginreplace,int appendhere,std::string streplace);
#pragma warning(disable:4996)
#endif