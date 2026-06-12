#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "lexer.h"

char *datakeywords[]={"int","float","char","double","short",
    "long","signed","unsigned","void"};   //datatypes
char *nonDatakeywords[]={"goto","return","continue","break","if",
    "for","else","while","do","switch","case","default","sizeof"}; //reserved (not datatypes)

int isDataKeyword(char *str)
{
    int n=sizeof(datakeywords)/sizeof(datakeywords[0]);  //to calculate no.of elements in array
    for(int i=0;i<n;i++)
    {
        if(strcmp(str,datakeywords[i])==0)
        {
            return 1;
        }
    }
    return 0;
}
int isnonDataKeyword(char *str)
{
    int n=sizeof(nonDatakeywords)/sizeof(nonDatakeywords[0]);
    for(int i=0;i<n;i++)
    {
        if(strcmp(str,nonDatakeywords[i])==0)
        {
            return 1;
        }
    }
    return 0;
}
int isOperator(char ch)
{
    return(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='=' ||
           ch=='<' || ch=='>');
}
int isSpclChar(char ch)
{
    return(ch=='(' || ch==')' || ch=='{' || ch=='}' || ch=='[' || ch==']' ||
           ch==';' || ch==',');
}
int isInteger(char *str)
{
    int i;

    for(i=0; str[i]!='\0'; i++)
    {
        if(!isdigit(str[i]))
            return 0;
    }

    return 1;
}
int isFloat(char *str)
{
    int dot = 0;  //decimal point

    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i] == '.')
            dot++;
        else if(!isdigit(str[i]))
            return 0;
    }
    return (dot==1);
}



