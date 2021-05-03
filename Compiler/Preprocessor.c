#include "Preprocessor.h"
int (*FunctionPtr_Hash[])(void) = {DefineProcess,IncludeProcess};

/*
Local Variable for all #s statements 
*/
char *matching[] = {"define","include"};
/*
Local Function
It is used to caompare the statement which get from "GetHashInst" and compares it with the saved statements in Matching Array
Return the number of equal statement or -1 if there is no such satatement
*/
static int matchingF(char *ptr);
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
void GetHashInst(FILE *fptr){
	char ch;
	char str[8];
	int i = 0;
	while ((ch = fgetc(fptr)) != ' '){
		str[i++] = ch;
		//printf("%c",ch);
	}
	str[i] =  '\0';
	printf("HI %s\n",str);
	if(matchingF(str) == -1){
			//Error Handling
	}
	else{
		//(*FunctionPtr_Hash[i])();
	}
}
static int matchingF(char *ptr){
	int i = 0;
	for(; i  < HashNumbers; i++){
		if( strCompare(ptr,matching[i]) == 1){
			printf("Matched %d\n",i);
			return i;
		}
	}
	printf("not Matched\n");
	return -1;
}


/*Need to implement Sama & Ali's Task
Returns the state Error , Warning or Success
*/
int DefineProcess(void){
	;
}
int IncludeProcess(void){
	;
}