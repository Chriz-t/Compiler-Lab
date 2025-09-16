#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char expr[30],postfix[30],stack[30];

int prec(char c){
	if(c=='^') return 3;
	else if(c=='/'||c=='*') return 2;
	else if(c=='+'||c=='-') return 1;
	else return -1;
}

void infixToPostfix(char *expr){
	int len=strlen(expr);
	int j=0,top=-1; 
	for(int i=0;i<len;i++){
		char c=expr[i];
		if(isalnum(c)) 
			postfix[j++]=c;
		else if(c=='(')
			stack[++top]=c;
		else if(c==')'){
			while(top!=-1&&stack[top]!='(')
				postfix[j++]=stack[top--];
			top--;
		}
		else{
			while(top!=-1&&(prec(c)<prec(stack[top])||prec(c)==prec(stack[top])))
				postfix[j++]=stack[top--];
			stack[++top]=c;
		}
	}
	while(top!=-1){
		postfix[j++]=stack[top--];
	}
	postfix[j]='\0';
	printf("Postfix expression:%s\n",postfix);
}

int main(int argc, char *argv[]) {
    FILE *fp1;
    fp1 = fopen(argv[1], "w");
    int start,i=0;
    char ch;
    printf("Enter the expression\n");
	scanf("%s",expr);
	infixToPostfix(expr);
	printf("Enter the starting address:\n");
	scanf("%d",&start);
	while((ch=postfix[i])!='\0'){
	    if(isalpha(ch)){
	        fprintf(fp1,"%d:MOV A, %c\n",start++,ch);
	        fprintf(fp1,"%d:PUSH  A\n",start++);
	    }else if(ch=='+'){
	        fprintf(fp1,"%d:POP  B\n",start++);
	        fprintf(fp1,"%d:POP  A\n",start++);
	        fprintf(fp1,"%d:ADD  B\n",start++);
	        fprintf(fp1,"%d:PUSH  A\n",start++);
	    }else if(ch=='-'){
	        fprintf(fp1,"%d:POP  B\n",start++);
	        fprintf(fp1,"%d:POP  A\n",start++);
	        fprintf(fp1,"%d:SUB  B\n",start++);
	        fprintf(fp1,"%d:PUSH  A\n",start++);
	    }else if(ch=='*'){
	        fprintf(fp1,"%d:POP  B\n",start++);
	        fprintf(fp1,"%d:POP  A\n",start++);
	        fprintf(fp1,"%d:MUL  B\n",start++);
	        fprintf(fp1,"%d:PUSH  A\n",start++);
	    }else if(ch=='+'){
	        fprintf(fp1,"%d:POP  B\n",start++);
	        fprintf(fp1,"%d:POP  A\n",start++);
	        fprintf(fp1,"%d:DIV  B\n",start++);
	        fprintf(fp1,"%d:PUSH  A\n",start++);
	    }
	        
	  
	    i++;
    }
    fprintf(fp1,"%d:POP  A\n",start++);
	fprintf(fp1,"%d:HLT\n",start++);
}
