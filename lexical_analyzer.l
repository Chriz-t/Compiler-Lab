%{
	#include<stdio.h>
	int flag=0;
	int line=1;
	int sl=1;
	FILE *fp;
%}
DIGIT[0-9]
ALPHA[a-zA-Z]
WS[ \t]
%%
{WS}+ {}
"\n" {line++;}
";" {fprintf(fp,"%d\t;\tSemincolon\t%d\n",sl,line);sl++;}
"{"|"("|"[" {fprintf(fp,"%d\t%s\tOpen_brckt\t%d\n",sl,yytext,line);sl++;}
"}"|")"|"]" {fprintf(fp,"%d\t%s\tClose_brckt\t%d\n",sl,yytext,line);sl++;}
"+"|"-"|"*"|"/" {fprintf(fp,"%d\t%s\tArith_op\t%d\n",sl,yytext,line);sl++;}
"<"|">"|"<="|">="|"!"|"!="|"==" {fprintf(fp,"%d\t%s\tReletnl_op\t%d\n",sl,yytext,line);sl++;}
"=" {fprintf(fp,"%d\t%s\tAssignmt_op\t%d\n",sl,yytext,line);sl++;}
"include"|""|"void"|"int"|"float"|"main"|"printf"|"return" {fprintf(fp,"%d\t%s\tKey_word\t%d\n",sl,yytext,line);sl++;}
{ALPHA}({ALPHA}|{DIGIT})* {fprintf(fp,"%d\t%s\tIdentifier\t%d\n",sl,yytext,line);sl++;}
{DIGIT}+"."{DIGIT}+ {fprintf(fp,"%d\t%s\tFloat\t%d\n",sl,yytext,line);sl++;}
{DIGIT}+ {fprintf(fp,"%d\t%s\tNumeric\t%d\n",sl,yytext,line);sl++;}
"&"|"%"|"#"|","|"." {fprintf(fp,"%d\t%s\tSpecial_chr\t%d\n",sl,yytext,line);sl++;}
. {fprintf(fp,"%d\t%s\tUnrecognized\t%d\n",sl,yytext,line);sl++;}
%%
void main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	fp=fopen(argv[2],"w");
	fprintf(fp,"Slno\tLexeme\tToken\tLineNo\n");
	yylex();
	fclose(fp);
}
int yywrap(){
	return 1;
}
