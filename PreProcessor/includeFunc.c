#include <stdio.h>
#include <stdlib.h>
#include "includeFunc.h"
//#include "RemoveCommentsFunction.h"

extern char *matching[];
static FILE *op1 = NULL;
void GetFilename(FILE *fptr);
FILE * IncludeFunction(FILE *fptr){
	FILE * newPtr;
	char ch;int i;
	printf("\n\nProcessing Phase Start:....\n\n");
		/*Creating a new file*/
	if(op1 == NULL){
	op1 = fopen("op1.i","w");
	}	
	while ((ch = fgetc(fptr)) != EOF)
        {
           if(ch == '#'){
			   //Go to Preprocessor Phase
			   i = GetHashInst(fptr);
			   if(i == 1){
				   //INCLUDE INSTRUCTION
				   	printf("Hear\n");
					GetFilename(fptr);
			   }
			   else{
				   //AnyThing else
				putc('#',op1);
				printf("#");
				printf("%s",matching[i]);
				fputs(matching[i],op1);
			   }
			   
		   }
		    else if(ch == '/'){
			   //Go to comment Handleng
			RemoveComments(&fptr,&op1);
		   }
		   else{
			   printf("%c",ch);
			   putc(ch,op1); 
        }
		}
		return op1;
}
void GetFilename(FILE *fptr){
	char ch;	FILE *PrtInclude;
	char str[30];	int i = 0;
	char flag = 0;char type = 0;
	ch = fgetc(fptr);
	printf("aasda = %c\n",ch);
	while( (ch != EOF) && (ch != '\n') )
    {	
		if(ch == '"'){
			if(flag == 1){
			break;
		}
		flag++;
		}
		else if( (ch == ' ') && (flag == 0)){
			;
		}
		else if(ch == '<'){
			flag = 1;
		}
		else if(ch == '>' && flag > 0){
			break;
		}
		else if(flag == 0){
			printf("#include expects \"FILENAME\" or <FILENAME>\n");
			exit(1);
		}
		else{
			str[i++] = ch;
		}
		ch = fgetc(fptr);
	}
	str[i] = '\0';
	//Open the included file
	if ((PrtInclude = fopen(str,"r")) == NULL){
       printf("fatal error: %s: No such file or directory compilation terminated.\n",str);
       exit(1);
   }
   else{
	   printf("Open File %s\n",str);
   }
   printf("Start Copying ...\n");
   IncludeFunction(PrtInclude);
   
}

/*
int IncludeProcess(FILE *fptr){
	char ch;
	char str[30];	int i = 0;
	char flag = 0;char type = 0;
	FILE *PrtInclude;
	ch = fgetc(fptr);
	while( (ch != EOF) && (ch != '\n') )
    {	
		if(ch == '"'){
			if(flag == 1){
			break;
		}
		flag++;
		}
		else if(ch == '<'){
			flag = 1;
		}
		else if(ch == '>' && flag > 0){
			break;
		}
		else if(flag == 0){
			printf("#include expects \"FILENAME\" or <FILENAME>");
			exit(1);
		}
		else{
			str[i++] = ch;
		}
		ch = fgetc(fptr);
	}
	str[i] = '\0';
	//Open the included file
	if ((PrtInclude = fopen(str,"r")) == NULL){
       printf("fatal error: %s: No such file or directory compilation terminated.\n",str);
       exit(1);
   }
   else{
	   printf("Open File %s\n",str);
   }
   printf("Start Copying ...\n");
   
   //Copy the file now
   char x ;
   while ((x = fgetc(PrtInclude)) != EOF)
	{
			putc(x,newPtr);
			printf("%c",x);
		}
	printf("end\n");
	fclose(PrtInclude);

}*/