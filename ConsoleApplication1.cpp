// calculator

#include "stdafx.h"
#include <iostream>
#include "operation.h"
#include "mylib.h"
using namespace std;

int main()
{
	while(true){
		char* input=getinput();
		int endset=GetTermLoc(input);
		solveset(input,0,&endset);
		delete input;
	}
	return 0;
}

