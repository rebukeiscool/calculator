#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

char* resize(char* cnarray){  //function that takes a character array as an argument and returns a pointer to a new array that is the right size
	int sizeofarray = 0;
	for(sizeofarray=0;cnarray[sizeofarray]!='\0';sizeofarray++){}
	char* input = new char[sizeofarray];
	for(sizeofarray=0;input[sizeofarray]!='\0';sizeofarray++){
		input[sizeofarray]=cnarray[sizeofarray];
	}
	return input;
}

void parsearray(char* cnarray){
	int counter=0;
	for(;;counter++){
		cout << "parsearray called" << endl << endl << counter+1 << "th element___" << cnarray[counter] << "___" << char(cnarray[counter]) << "___" << int(cnarray[counter]);
		if(cnarray[counter])
			cout << "___true" << endl;
		else cout << "___false" << endl;
		if(cnarray[counter]=='\0'){
			cout << "terminating char reached @ index of " << counter << endl;
			break;
		}
	}
	return;
}

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

string getinput(){
	string input="";
	cout << "Enter problem" << endl;
	getline(cin,input);
	return input;
}

void AddTermChar(char* cstring){
	int counter=0;
	for(;cstring[counter];counter++){}
	cstring[counter]='\0';
	return;
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