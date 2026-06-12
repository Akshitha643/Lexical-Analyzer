/*
NAME		: G AKSHITHA REDDY
DATE		: 11 JUNE, 2026
PROJECT 	: LEXICAL ANALYZER
*/

#include<stdio.h>
#include<ctype.h>
#include "lexer.h"

int main()
{
    FILE *fptr;
    char ch;
    char token[100];
    int i = 0;

    fptr = fopen("text.c", "r");

    if(fptr == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    printf("\nOUTPUT\n\n");

    while((ch = fgetc(fptr)) != EOF)
    {
        if(isalnum(ch) || ch == '_' || ch == '.')
        {
            token[i++] = ch;
        }
        else
        {
            if(i != 0)
            {
                token[i] = '\0';

                if(isDataKeyword(token))
                {
                    printf("Reserved Keyword(Data Type)      : %s\n", token);
                }
                else if(isnonDataKeyword(token))
                {
                    printf("Reserved Keyword(Non Data Type)  : %s\n", token);
                }
                else if(isInteger(token))
                {
                    printf("Integer Literal                  : %s\n", token);
                }
                else if(isFloat(token))
                {
                    printf("Float Literal                    : %s\n", token);
                }
                else
                {
                    printf("Identifier                       : %s\n", token);
                }

                i = 0;
            }

            if(isOperator(ch))
            {
                printf("Operator                         : %c\n", ch);
            }
            else if(isSpclChar(ch))
            {
                printf("Special Character                : %c\n", ch);
            }
        }
    }

    fclose(fptr);

    return 0;
}
	
