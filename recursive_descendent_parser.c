#include<stdio.h>
int count=0;
char str[100];
/*  For the grammer E->E+E/E*E/(E)/i  */

int E(){
	printf("Expanding E->TE1\n");
	if(T()==1){
		if(E1()==1){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

int E1(){
	if(str[count]=='+'){
		printf("Expanding E1->+TE1\n");
		printf("Consuming +\n");
		count++;
		if(T()==1){
			if(E1()==1){
				return 1;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else{
		printf("Expanding E1->e\n");
		return 1;
	}
}

int T(){
	printf("Expanding T->FT1\n");
	if(F()==1){
		if(T1()==1){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

int T1(){
	if(str[count]=='*'){
		printf("Expanding T1->*FT1\n");
		printf("Consuming *\n");
		count++;
		if(F()==1){
			if(T1()==1){
				return 1;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else{
		printf("Expanding T1->e\n");
		return 1;
	}
}

int F(){
	if(str[count]=='('){
		printf("Expanding F->(E)\n");
		printf("Consuming (\n");
		count++;
		if(E()==1){
			if(str[count]==')'){
				printf("Consuming )\n");
				count++;
				return 1;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else if(str[count]=='i'){
		printf("Expanding F->i\n");
		printf("Consuming i\n");
		count++;
		return 1;
	}
}

int main(){
	printf("Enter the string:\t");
	scanf("%s",str);
	if(E()==1&&str[count]=='\0'){
		printf("The string is Accepted\n");
	}else{
		printf("The string is Rejected\n");
	}
}
