#include <stdio.h>
#include <stdlib.h>
#include "Preprocessor.h"
int main(int argc, char *argv[])
{
   int num;
   FILE *fptr;
   printf("First argument is: %s\n", argv[1]);   
   if ((fptr = fopen(argv[1],"r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
	char ch;
	while ((ch = fgetc(fptr)) != EOF)
        {
           if(ch == '#'){
			   //Go to Preprocessor Phase
			   GetHashInst(fptr);
		   }
		   else{
			   printf("%c",ch);
        }
		}
		fclose(fptr);
    return 0;
}