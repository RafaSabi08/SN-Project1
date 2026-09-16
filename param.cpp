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
	argumentVector[0] = NULL;
}

void Param::addArgument (char* newArgument)
{
	if(argumentCount >= MAXARGS) {
		cerr << "Error: Too many arguments." << endl;
		return;
	}
	argumentVector[argumentCount] = newArgument;
	argumentCount++;
	if (argumentCount < MAXARGS) {
		argumentVector[argumentCount] = NULL;  // marca o fim da lista, igual '\0' marca o fim de uma string
	}
}

char** Param::getArguments()
{
	return argumentVector;
}

void Param::setInputRedirect(char *newInputRedirect)
{
	inputRedirect = newInputRedirect;
}

void Param::setOutputRedirect(char *newOutputRedirect)
{
	outputRedirect = newOutputRedirect;
}
		
void Param::setBackground(int newBackground)
{
	background = newBackground;
}

char* Param::getInputRedirect()
{
	//finish this
	return inputRedirect;
}
		
		
char* Param::getOutputRedirect()
{
	//finish this
	return outputRedirect;
}
		
int Param::getBackground()
{
	// finish this
    return background;
}


void Param::printParams() {
	cout << "InputRedirect: [" 
	     << ((inputRedirect != NULL) ? inputRedirect : "NULL");
	cout << "]" 
	     << endl 
		 <<	"OutputRedirect: [" 
		 << ((outputRedirect != NULL) ? outputRedirect : "NULL");
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
