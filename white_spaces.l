%{
	#include<stdio.h>
	int flag;
	FILE *fp;
%}
WS[ \t]
%%
{WS}+ {}
"//" {flag=1;}
"\n" {if(flag==1){flag=0;}}
"/*" {flag=2;}
"*/" {if(flag==2){flag=0;}else if(flag==0){fprintf(fp,"%s",yytext);}}
. {if(flag==0){fprintf(fp,"%s",yytext);}}
%%
void main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	fp=fopen(argv[2],"w");
	yylex();
}
int yywrap(){
	return 1;
}
