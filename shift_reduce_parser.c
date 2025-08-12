#include<stdio.h>

int j=0,top=0,sl=0;
char input[50],stack[50],ch;

void reduce(){
    int z=0;
    for(z=0;z<top;z++){
        if(stack[z]=='i'){
            stack[z]='E';
            printf("\n%d\t$%s\t%s$\tReduce E->i",sl,stack,input);
            sl++;        
        }
    }
    for(z=0;z<top;z++){
        if(stack[z]=='('&&stack[z+1]=='E'&&stack[z+2]==')'){
            stack[z]='E';
            printf("\n%d\t$%s\t%s$\tReduce E->(E)",sl,stack,input);
            sl++;        
        }
    }
    for(z=0;z<top;z++){
        if(stack[z]=='E'){
            if(stack[z+1]=='+'&&stack[z+2]=='E'){
                stack[z]='E';
                top-=2;
                stack[top]='\0';
                printf("\n%d\t$%s\t%s$\tReduce E->E+E",sl,stack,input);
                sl++;
            }else if(stack[z+1]=='*'&&stack[z+2]=='E'){
                stack[z]='E';
                top-=2;
                stack[top]='\0';
                printf("\n%d\t$%s\t%s$\tReduce E->E*E",sl,stack,input);
                sl++;
            }       
        }
    }
}

int main(){
    printf("Enter the string:\t");
    scanf("%s",input);
    printf("SlNo\tStack\tInput\tAction");
    while(input[j]!='\0'){
        ch=input[j];
        stack[top++]=ch;
        stack[top]='\0';
        input[j]=' ';
        printf("\n%d\t$%s\t%s$\tShift %c",sl,stack,input,ch);
        sl++;
        j++;
        reduce();
    }
    if(stack[0]=='E'&&stack[1]=='\0'){
        printf("\nString is Accepted!\n");
    }else{
        printf("\nString is Rejected!\n");
    }
}
