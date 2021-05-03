#ifndef PREPROCESSOR
#define PREPROCESSOR
#include <stdio.h>
#include <stdlib.h>
//Not used et
typedef enum HashInst{
	define,
	include,
}HashInst;
/*
This function is called when # is found at the code
Input: Pointer to file is pointed to the next char after #
Processes:
it concatenates all chars till it find " "-space-
*/
void GetHashInst(FILE *fptr);
#define HashNumbers 2
int DefineProcess(void); 
int IncludeProcess(void); 


#endif