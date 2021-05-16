#include <stdio.h>
#include <stdlib.h>
#include "PreProcessor/Preprocessor.h "
int main(int argc, char *argv[])
{
   int num,result;
   FILE *fptr;
   char ModifiedFile[30];
   printf("First argument is: %s\n", argv[1]);   
   if ((fptr = fopen(argv[1],"r")) == NULL){
       printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   /*creating a new file.i*/
		int i = 0;
		while(argv[1][i] != '.'){
			ModifiedFile[i] = argv[1][i++];
		}
		ModifiedFile[i++] = '.';
		ModifiedFile[i++] = 'i';
		ModifiedFile[i] = '\0';
		printf("New File name:%s\n",ModifiedFile);
  
		result = Preprocessor_Phase(fptr,ModifiedFile);
		printf("\nBack Main:\n");

		fclose(fptr);
    return 0;
}