#include <stdio.h>
#include <stdlib.h>
#include "RemoveCommentsFunction.h"

int RemoveComments( FILE **P_ReadFile, FILE **P_WriteFile)
{
	char chr1 = fgetc(*P_ReadFile);
	char chr = '/';
	if (chr1 == '/')
	{
		/*One Line Comment*/
		while (chr != '\n')
		{
		ungetc(' ', *P_WriteFile);
		chr = fgetc(*P_ReadFile);
		}
	}
	else if (chr1 == '*')
	{
		while ((chr != '*') && (chr != EOF))
		{
			ungetc(' ', *P_WriteFile);
			chr = fgetc(*P_ReadFile);
		}			
		if (chr == '*')
		{
			chr1 = fgetc(*P_ReadFile);
			if (chr1 == '/')
			{
				ungetc(' ', *P_WriteFile);
				chr = fgetc(*P_ReadFile);	
			}
		}
		if(chr == EOF){
		printf("error: unterminated comment\n");
		return -1;}
	}	
	else
	{
		fputc(chr,*P_WriteFile);
		fputc(chr1,*P_WriteFile);		
		//chr=fgetc(*P_ReadFile);
	}
	return 1;
}






