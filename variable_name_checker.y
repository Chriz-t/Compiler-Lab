%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
%}
%token DIGIT
%token ALPHA
%%
L:A'\n' {printf("Variable name is Valid\n"); return 0;}
;
A:ALPHA B
| ALPHA
;
B:ALPHA B
| DIGIT B
| ALPHA
| DIGIT
;
%%
yylex(){
    char ch;
    ch=getchar();
    if(isdigit(ch)){
        return DIGIT;
    }else if(isalpha(ch)){
        return ALPHA;
    }else{
        return ch;
    }
}
void main(){
    printf("Enter the Variable Name:\t");
    yyparse();
}
yyerror(){
    printf("\nVariable name is Invalid");
    exit(0);
}
