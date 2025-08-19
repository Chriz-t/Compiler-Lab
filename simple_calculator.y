%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
%}
%token NUMBER
%%
L:E'\n' {printf("Result is %d",$1); return 0;}
;
E:E'+'T {$$=$1+$3;}
| T {$$=$1;}
;
T:T'*'F {$$=$1*$3;}
| F {$$=$1;}
;
F:NUMBER {$$=$1;}
;
%%
yylex(){
    char ch;
    ch=getchar();
    if(isdigit(ch)){
        ungetc(ch,stdin);
        scanf("%d",&yylval);
        return NUMBER;
    }else{
        return ch;
    }
}
void main(){
    printf("Enter the expression:\t");
    yyparse();
}
yyerror(){
    printf("\nInvalid Expresion");
    exit(0);
}
