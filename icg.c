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
	
	while(top!=-1)
		postfix[j++]=stack[top--];
	
	postfix[j]='\0';
	printf("Postfix expression:%s\n",postfix);
}

void TAC(){
	int top=-1,sl_no=1,i=0;
	char ch,ch1,ch2;
	printf("\nThree Address Code\n");
	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isalpha(ch))
			stack[++top]=ch;
		else{
			ch2=stack[top--];
			ch1=stack[top--];
			
			if(isalpha(ch1)&&isalpha(ch2))
				printf("t%d=%c%c%c\n",sl_no,ch1,ch,ch2);
			else if(isalpha(ch1)&&isdigit(ch2))
				printf("t%d=%c%ct%c\n",sl_no,ch1,ch,ch2);
			else if(isdigit(ch1)&&isalpha(ch2))
				printf("t%d=t%c%c%c\n",sl_no,ch1,ch,ch2);
			else if(isdigit(ch1)&&isdigit(ch2))
				printf("t%d=t%c%ct%c\n",sl_no,ch1,ch,ch2);
				
			stack[++top]=(sl_no+'0');
			sl_no++;
		}
		i++;
	}
}


void quadruple(){
	int top=-1,sl_no=1,i=0;
	char ch,ch1,ch2;
	printf("\nQuadruple\n");
	printf("op\targ1\targ2\tres\n");
	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isalpha(ch))
			stack[++top]=ch;
		else{
			ch2=stack[top--];
			ch1=stack[top--];
			
			if(isalpha(ch1)&&isalpha(ch2))
				printf("%c\t%c\t%c\tt%d\n",ch,ch1,ch2,sl_no);
			else if(isalpha(ch1)&&isdigit(ch2))
				printf("%c\t%c\tt%c\tt%d\n",ch,ch1,ch2,sl_no);
			else if(isdigit(ch1)&&isalpha(ch2))
				printf("%c\tt%c\t%c\tt%d\n",ch,ch1,ch2,sl_no);
			else if(isdigit(ch1)&&isdigit(ch2))
				printf("%c\tt%c\tt%c\tt%d\n",ch,ch1,ch2,sl_no);
				
			stack[++top]=sl_no+'0';
			sl_no++;
		}
		i++;
	}
}


void triple(){
	int top=-1,sl_no=1,i=0;
	char ch,ch1,ch2;
	printf("\nTriple\n");
	printf("  \top\targ1\targ2\n");
	while(postfix[i]!='\0'){
		ch=postfix[i];
		if(isalpha(ch))
			stack[++top]=ch;
		else{
			ch2=stack[top--];
			ch1=stack[top--];
			
			if(isalpha(ch1)&&isalpha(ch2))
				printf("(%d)\t%c\t%c\t%c\n",sl_no-1,ch,ch1,ch2);
			else if(isalpha(ch1)&&isdigit(ch2))
				printf("(%d)\t%c\t%c\t(%c)\n",sl_no-1,ch,ch1,ch2-1);
			else if(isdigit(ch1)&&isalpha(ch2))
				printf("(%d)\t%c\t(%c)\t%c\n",sl_no-1,ch,ch1-1,ch2);
			else if(isdigit(ch1)&&isdigit(ch2))
				printf("(%d)\t%c\t(%c)\t(%c)\n",sl_no-1,ch,ch1-1,ch2-1);
				
			stack[++top]=sl_no+'0';
			sl_no++;
		}
		i++;
	}
}

int main(){
	printf("Enter the expression\n");
	scanf("%s",expr);
	infixToPostfix(expr);
	TAC();
	quadruple();
	triple();
}
