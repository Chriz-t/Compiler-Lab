%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
%}
%token NUMBER
%left '+''-'
%left '*''/'
%right UMINUS
%%
L:E'\n' {printf("Result is %d",$1); return 0;}
;
E:E'+'E {$$=$1+$3;}
| E'-'E {$$=$1-$3;}
| E'*'E {$$=$1*$3;}
| E'/'E {$$=$1/$3;}
| '('E')' {$$=$2;}
| '-'E %prec UMINUS {$$=-$2;}
| NUMBER {$$=$1;}
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
