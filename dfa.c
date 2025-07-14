#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int indexof(char s[],int n,char a){
    for(int i=0;i<n;i++){
        if(a==s[i]){
            return i;
        }
    }
}

int isAcc(int fs[],int n,int cs){
    for(int i=0;i<n;i++){
        if(cs==fs[i]){
            return 1;
        }
    }
    return 0;
}

int main(){
    int state_count,symbol_count,final_count,final_states[100],current_state;
    printf("Enter the no of states: ");
    scanf("%d",&state_count);
    printf("Enter the no of alphabets: ");
    scanf("%d",&symbol_count);
    char symbols[100],str[100],ch;
    printf("Enter the input symbols: ");
    scanf("%s",symbols);
    printf("Enter the transition matrix: ");
    int transition_table[100][100];
    for(int i=0;i<state_count;i++){
        for(int j=0;j<symbol_count;j++){
            scanf("%d",&transition_table[i][j]);
        }
    }
    printf("Enter the no of final states: ");
    scanf("%d",&final_count);
    printf("Enter the final states: ");
    for(int i=0;i<final_count;i++){
        scanf("%d",&final_states[i]);
    }
    while(1){
        printf("Enter the string: ");
        scanf("%s",str);
        int len=strlen(str);
        current_state=0;
        for(int i=0;i<len;i++){
            ch=str[i];
            current_state=transition_table[current_state][indexof(symbols,symbol_count,ch)];
        }
        if(isAcc(final_states,final_count,current_state)){
            printf("The string is Accepted!\n");
        }else{
            printf("The string is Rejected!\n");
        }
    }
}
