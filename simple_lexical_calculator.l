%{
	#include<stdio.h>
	int flag=0,a;
%}
DIGIT[0-9]

%%
"+" {flag=1;}
"-" {flag=2;}
"*" {flag=3;}
"/" {flag=4;}
{DIGIT}+ {if(flag==0){ a=atoi(yytext); }else if(flag==1){a+=atoi(yytext);}else if(flag==2){a-=atoi(yytext);}else if(flag==3){a*=atoi(yytext);}else if(flag==4){a/=atoi(yytext);}}
"\n" {printf("\nThe result is %d",a);}
. {printf("Unknown Operator %c\n",yytext);}
%%
void main(int argc, char *argv[]){
    printf("Enter the expression:\n");
	yyin=stdin;
	yylex();
}
int yywrap(){
	return 1;
}
