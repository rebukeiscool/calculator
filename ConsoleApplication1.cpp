// calculator

#include "stdafx.h"
#include <iostream>
#include "operation.h"
#include "mylib.h"
#include <string>
using namespace std;

int main()
{
	while(true){
		string input=getinput();
		int endset=input.size()-1;
		const int startset=0;
		solveset(&input,startset,&endset);
		cout << input << endl;
	}
	return 0;
}

