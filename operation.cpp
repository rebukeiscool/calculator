#include "stdafx.h"
#include <iostream>
#include "operation.h"
#include <string>
#include "mylib.h"
#include "math.h"
#include <cmath>
using namespace std;
#define tempisnum ((int(input[tempcount])<58&&int(input[tempcount])>47)||(int(input[tempcount])==46))
#define isnum ((int(input[counter])<58&&int(input[counter])>47)||(int(input[counter])==46))
#define isop input[counter]=='+'||input[counter]=='-'||input[counter]=='*'||input[counter]=='/'||input[counter]=='('||input[counter]==')'||input[counter]=='^'
#define isperiod input[counter]=='.'

void solveset(char* input, int startset, int* endset){
	DoParenth(input,startset,endset);
	DoExp(input,startset,endset);
	DoMultiDiv(input,startset,endset);
	DoPlusMinus(input,startset,endset);
	return;
}

void DoExp(char* input, int startset, int* endset){
	int counter=startset;
	for(;counter<=*endset;counter++){
		if(input[counter]=='^'){
			int tempcount=counter-1;
			for(;tempisnum;tempcount--){
				if(tempcount<startset) break;
				if(tempcount==0){
					tempcount--;
					break;
				}
			}
			tempcount++;
			int startreplace=tempcount;
			double dleft=0;
			double* pleft=&dleft;
			getTerm(input,tempcount,pleft);
			double dright=0;
			double* pright=&dright;
			
			for(;tempisnum;tempcount++){
				if(tempcount>*endset){
					cout << "error. right term is outside of set" << endl;
					return;
				}
			}
			tempcount++;
			getTerm(input,tempcount,pright);
			double danswer=pow(dleft,dright);
			string stanswer= to_string(danswer);

			for(;tempisnum;tempcount++){}
			int appendhere=tempcount;
			AnsReplace(input,startreplace,appendhere,stanswer);
		}
	}
	return;
}

void DoMultiDiv(char* input, int startset, int* endset){
	return;
}

void DoPlusMinus(char* input, int startset, int* endset){
	return;
}

void getTerm(char* input,int counter,double* term){
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
	return;
}

void DoParenth(char* input,int startset,int* endset){
	return;
}

void AnsReplace(char* input,int beginreplace,int appendhere,string streplace){
	int counter=appendhere;
	int tempcount=0;
	string appendthis="";
	string stinput="";
	for(;input[counter]!='\0';counter++,tempcount++){}
	appendthis.append(&(input[appendhere]),tempcount);
	char* deletethis=&(input[0]);
	input = new char[strlen(input)];
	strncpy(input,deletethis,beginreplace);
	strncpy(&(input[beginreplace]),streplace.c_str(),streplace.size());
	strncpy(&(input[beginreplace+streplace.size()]),appendthis.c_str(),appendthis.size());
	input[beginreplace+streplace.size()+appendthis.size()]='\0';
	int initial=appendhere-beginreplace;
	cout << initial << endl;
	delete deletethis;
	return;
}

void HandleParenth(char* input,int openpar,int* closepar){
	return;
}