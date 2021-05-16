#ifndef PREPROCESSOR_H_
#define PREPROCESSOR_H_
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
int GetHashInst(FILE* );
int Preprocessor_Phase(FILE *fptr,char *resultFile);
#define HashNumbers 2



#endif