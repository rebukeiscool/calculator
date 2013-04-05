#include "stdafx.h"
#include <iostream>
#include "operation.h"
#include <string>
#include "mylib.h"
#include "math.h"
#include <cmath>
using namespace std;
#define BUFFER 50
#define tempisnum ((int(input[tempcount])<58&&int(input[tempcount])>47)||(int(input[tempcount])==46))
#define isnum ((int(input[counter])<58&&int(input[counter])>47)||(int(input[counter])==46))
#define isop (input[counter]=='+'||input[counter]=='-'||input[counter]=='*'||input[counter]=='/'||input[counter]=='('||input[counter]==')'||input[counter]=='^')
#define isperiod input[counter]=='.'

void solveset(string* pstrinput, int startset, int* endset){
	DoParenth(pstrinput,startset,endset);
	DoExp(pstrinput,startset,endset);
	//DoMultiDiv(pstrinput,startset,endset);
	//DoPlusMinus(pstrinput,startset,endset);
	return;
}

void DoExp(string* pstrinput, int startset, int* endset){
	char* input=new char[pstrinput->size()+1];
	strcpy(input,pstrinput->c_str());
	int counter=startset;
	for(;counter<=*endset;counter++){
		if(input[counter]=='^'){
			if(counter==0){cout << "error. '^' found @ beginning of set" << endl;}
			if(counter==*endset){cout << "error. '^' found @ end of set" << endl;}
			double dleft=0;
			double dright=0;
			double* pleft=&dleft;
			double* pright=&dright;
			getTerm(pstrinput,LocateLeftTerm(pstrinput,counter),pleft);
			getTerm(pstrinput,LocateRightTerm(pstrinput,counter),pright);
			double danswer=0;
			danswer+=pow(dleft,dright);
			string streplace = to_string(danswer);
			AnsReplace(pstrinput,LocateLeftTerm(pstrinput,counter),GetEndBinaryOp(pstrinput,counter)+1,streplace,endset);
			break;
		}
		else{continue;}
	}
	delete[] input;
	return;
}

void DoMultiDiv(string* pstrinput, int startset, int* endset){
	return;
}

void DoPlusMinus(string* pstrinput, int startset, int* endset){
	return;
}

void getTerm(string* pstrinput,int counter,double* term){
	char* input=new char[pstrinput->size()+1];
	strcpy(input,pstrinput->c_str());
	if(!isnum){
		cout << "error in getTerm. current char is "<< input[counter] << endl;
		return;
	}
	int ndigit=10;
	int ndecimal=0;
	for(;isnum;counter++){
		if(input[counter]=='.'){
			if(ndecimal){
				cout << "error in getTerm" << endl;
				return;
			}
			else{
				*term/= power(10,ndigit);
				ndecimal++;
				continue;
			}
		}
		else{
			if(ndecimal){
				if(input[counter]=='0'){
					ndecimal++;
					continue;
				}
				else{
					*term+=(double(input[counter])-48)*power(10,-ndecimal);
					ndecimal++;
					continue;
				}
			}
			else{
				if(input[counter]=='0'){
					ndigit--;
					continue;
				}
				else{
					ndigit--;
					*term+=(double(input[counter])-48)*power(10,ndigit);
					continue;
				}
			}
		}
	}
	if(!ndecimal) *term/=power(10,ndigit);
	delete[] input;
	return;
}

void DoParenth(string* pstrinput,int startset,int* endset){
	return;
}

void AnsReplace(string* pstrinput,int beginreplace,int appendhere,string streplace,int* endset){
	string strinput="";
	string append="";
	append.append(*pstrinput,appendhere,BUFFER);
	strinput.append(*pstrinput,0,beginreplace);
	strinput.append(streplace);
	strinput.append(append);
	int addtoendset=strinput.size()-pstrinput->size();
	*endset+=addtoendset;
	*pstrinput=strinput;
	return;
}

void HandleParenth(string* pstrinput,int openpar,int* closepar){
	return;
}

int LocateLeftTerm(string* pstrinput,int counter){
	char* input=new char[pstrinput->size()+1];
	strcpy(input,pstrinput->c_str());
	if(!isop){cout << "error. input[counter] in LocateLeftTerm is not an operator" << endl;}
	for(counter--;isnum;counter--){
		if(counter==0){
			counter--;
			break;
		}
	}
	counter++;
	delete[] input;
	return counter;
}

int LocateRightTerm(string* pstrinput,int counter){
	char* input=new char[pstrinput->size()+1];
	strcpy(input,pstrinput->c_str());
	if(!isop){cout << "error. input[counter] in LocateRightTerm is not an operator" << endl;}
	delete[] input;
	return counter+1;
}

int GetEndBinaryOp(string* pstrinput,int counter){
	char* input=new char[pstrinput->size()+1];
	strcpy(input,pstrinput->c_str());
	if(!isop){cout << "error. input[counter] in GetEndBinaryOp is not an operator" << endl;}
	for(counter++;isnum;counter++){}
	return counter-1;
}