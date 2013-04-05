#ifndef OPERATION_H
#define OPERATION_H
#include <string>
void solveset(std::string* pstrinput, int startset, int* endset);
void DoParenth(std::string* pstrinput, int startset, int* endset);
void DoExp(std::string* pstrinput, int startset, int* endset);
void DoMultiDiv(std::string* pstrinput, int startset, int* endset);
void DoPlusMinus(std::string* pstrinput, int startset, int* endset);
void getTerm(std::string* pstrinput,int counter,double* term);
void DoParenth(std::string* pstrinput,int startset,int* endset);
void HandleParenth(std::string* pstrinput,int openpar,int* closepar);
void AnsReplace(std::string* pstrinput,int beginreplace,int appendhere,std::string streplace,int* endset);
int LocateLeftTerm(std::string* pstrinput,int counter);
int LocateRightTerm(std::string* pstrinput,int counter);
int GetEndBinaryOp(std::string* pstrinput,int counter);
#pragma warning(disable:4996)
#endif