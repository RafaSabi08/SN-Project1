/**
 *  param.hpp
 *  
 *  Thomas Reichherzer
 *  Copyright 2009 UWF - CS. All rights reserved.
 *
 */

#ifndef _PARAM_CPP
#define _PARAM_CPP

#include <iostream>

#include "param.hpp"

using  namespace std;

Param::Param() 
{
	inputRedirect = outputRedirect = NULL;
	background = 0;
	argumentCount = 0;
}

void Param::addArgument (char* newArgument)
{
	// finish this
}

char** Param::getArguments()
{
	// finish this
	return NULL;
}

void Param::setInputRedirect(char *newInputRedirect)
{
	//finish this
}

void Param::setOutputRedirect(char *newOutputRedirect)
{
	//finish this
}
		
void Param::setBackground(int newBackground)
{
	//finish this
}

char* Param::getInputRedirect()
{
	//finish this
	return NULL;
}
		
		
char* Param::getOutputRedirect()
{
	//finish this
	return NULL;
}
		
int Param::getBackground()
{
	// finish this
    return 0;
}


void Param::printParams() {
	cout << "InputRedirect: [" 
	     << (inputRedirect != NULL) ? inputRedirect : "NULL";
	cout << "]" 
	     << endl 
		 <<	"OutputRedirect: [" 
		 << (outputRedirect != NULL) ? outputRedirect : "NULL";
	cout << "]" 
	     << endl 
		 << "Background: [" 
		 << background 
		 << "]" 
		 << endl 
		 << "ArgumentCount: [" 
		 << argumentCount 
		 << "]" 
		 << endl;
	for (int i = 0; i < argumentCount; i++)
		cout << "ArgumentVector[" 
			 << i 
			 << "]: [" 
			 << argumentVector[i] 
			 << "]" 
			 << endl;
}

#endif
