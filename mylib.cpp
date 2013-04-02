#include "stdafx.h"
#include <iostream>
using namespace std;

void delspace(char* input){
	int icnt=0;
	int incnt=0;
	for(;input[icnt];icnt++){
		if(input[icnt]==' '){
			incnt=icnt;
			while(input[incnt]){
				input[incnt]=input[incnt+1];
				incnt++;
			}
			if(input[icnt]==' '){
				icnt--;
				continue;
			}
			else continue;
		}
		else continue;
	}
	return;
}

double power(double base, double power){
	int counter=1;
	double returnvalue=base;
	if(power>0){
		for(;counter<power;counter++){
			returnvalue*=base;
		}
	}
	if(power<0){
		power*=-1;
		for(;counter<power;counter++){
			returnvalue*=base;
		}
		returnvalue=1/returnvalue;
	}
	return returnvalue;
}

char* getinput(){
	char* input=new char[50];
	cout << "Enter problem" << endl;
	cin.getline(input,50,'\n');
	int counter=0;
	for(;input[counter];counter++){}
	input[counter]='\0';
	return input;
}


int GetTermLoc(char* cstring){
	if(!cstring){
		cout << "error. false cstring passed" << endl;
		return 0;
	}

	int counter=0;
	for(;;counter++){
		if(cstring[counter]=='\0'){
			return counter;
		}
	}
	return 0; //should never get here
}