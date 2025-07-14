#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp1,*fp2;
    fp1=fopen(argv[1],"r");
    fp2=fopen(argv[2],"w");
    char ch,ch1,ch2,ch3;
    while((ch=fgetc(fp1))!=EOF){
        switch(ch){
            case ' ':
                break;
            case '\t':
                break;
            case '\n':
                break;
            case '/':
                ch1=fgetc(fp1);
                if(ch1=='/'){
                    while((ch1=fgetc(fp1))!='\n');
                }else if(ch1=='*'){
                    ch2=fgetc(fp1);
                    ch3=fgetc(fp1);
                    while(!(ch2=='*'&&ch3=='/')){
                        ch2=ch3;
                        ch3=fgetc(fp1);
                    }
                }else{
                    fputc(ch,fp2);
                    ungetc(ch1,fp1);
                }
                break;
            default:
                fputc(ch,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
}
