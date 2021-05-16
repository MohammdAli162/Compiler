#include <stdio.h>
#include <stdlib.h>
#include "Preprocessor.h"
#include "includeFunc.h"
#include "RemoveCommentsFunction.h"
/*
Local Variable for all #s statements 
*/
char *matching[] = {"define","include","/",
					"warn","error",
					"ifdef","ifndef","undef",
					"if","endif","elseif","else"};
FILE *newPtr;
int DefineProcess(FILE*); 
//int (*FunctionPtr_Hash[HashNumbers])(FILE*) = {DefineProcess,IncludeFunction};



/*
Local Function
It is used to caompare the statement which get from "GetHashInst" and compares it with the saved statements in Matching Array
Return the number of equal statement or -1 if there is no such satatement
*/
extern int matchingF(char *ptr);
/*
Helper function to compare to strings return 1 on success
*/
int strCompare(char *str1,char *str2){
{
   int c = 0;
 
   while (str1[c] == str2[c]) {
      if (str1[c] == '\0' || str2[c] == '\0')
         break;
      c++;
   }
   
   if (str1[c] == '\0' && str2[c] == '\0')
      return 1;
   else
      return -1;
}
}
int Preprocessor_Phase(FILE *fptr,char *resultFile){
	char ch;FILE* op1;
	op1 = IncludeFunction(fptr);
	fclose(op1);
	printf("\n\nProcessing Phase Start:....\n\n");
	newPtr = fopen(resultFile,"w");	
	fptr = fopen("op1.i","r");	
		//Creating a new file
	printf("\n\nRemoveComments Phase Start:....\n\n");
	
	while ((ch = fgetc(fptr)) != EOF)
        {
           if(ch == '#'){
			   //Go to Preprocessor Phase
			   GetHashInst(fptr);
		   }
		   else if(ch == '/'){
			   //Go to comment Handleng
			RemoveComments(&fptr,&newPtr);
		   }
		   else{
			   printf("%c",ch);
			   putc(ch,newPtr); 
        }
		}
	printf("\n\nProcessing Phase Ended///////\n\n");
	return 0;
}

int GetHashInst(FILE *Mainfile){
	char ch;
	char str[8];
	int i = 0;
	/*
	Handline these cases:
		1- Inst "
		2- Inst<
		3- Inst"
	*/
	ch = fgetc(Mainfile);
	while((ch != ' ') && (ch != '"') && (ch != '<')){
		str[i++] = ch;
		ch = fgetc(Mainfile);
	}
	str[i] =  '\0';
	char result = matchingF(str);
	if(result == -1){
			//Error Handling
			printf("No Such a preprocessor Instruction %str \n",str);
			exit(1);
	}
	else{
		fseek(Mainfile,-1, SEEK_CUR );
		printf("Matched %d\n",result);
		return result;
	}
}
int matchingF(char *ptr){
	int i = 0;
	for(; i  < HashNumbers; i++){
		if( strCompare(ptr,matching[i]) == 1){
			
			return i;
		}
	}
	printf("not Matched\n");
	return -1;
}


/*Need to implement Sama & Ali's Task
Returns the state Error , Warning or Success
*/
int DefineProcess(FILE *fptr){
	;
}