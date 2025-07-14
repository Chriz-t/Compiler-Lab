#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    char ch, ch1, lexeme[50];
    int line = 1, sl = 1, i = 0, flag = -1;
    char keywords[20][50] = {"int", "float", "void", "char", "main", "while", "if", "printf", "scanf", "return","argc","argv","FILE","fopen","fprintf","while","else","break","ungetc","fclose"};
    fprintf(fp2, "Slno\tLexeme\tToken\tLineNo");
    while ((ch = fgetc(fp1)) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (i > 0) {
                lexeme[i] = '\0';
                if (flag == 0) {
                    fprintf(fp2, "\n%d\t%s\tNumeric\t%d", sl++, lexeme, line);
                } else if (flag == 1) {
                    fprintf(fp2, "\n%d\t%s\tFloatingPoint\t%d", sl++, lexeme, line);
                } else if (flag == 2) {
                    int is_keyword = 0;
                    for (int k = 0; k < 10; k++) {
                        if (strcmp(keywords[k], lexeme) == 0) {
                            is_keyword = 1;
                            break;
                        }
                    }
                    if (is_keyword) {
                        fprintf(fp2, "\n%d\t%s\tKeyword\t%d", sl++, lexeme, line);
                    } else {
                        fprintf(fp2, "\n%d\t%s\tIdentifier\t%d", sl++, lexeme, line);
                    }
                }
                i = 0;
                flag = -1;
            }
            if (ch == '\n') {
                line++;
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            fprintf(fp2, "\n%d\t%c\tArithmatic_operator\t%d", sl++, ch, line);
        } else if (ch == '=') {
            ch1 = fgetc(fp1);
            if (ch1 == '=') {
                fprintf(fp2, "\n%d\t==\tRelational_operator\t%d", sl++, line);
            } else {
                ungetc(ch1, fp1);
                fprintf(fp2, "\n%d\t=\tAssignment_operator\t%d", sl++, line);
            }
        } else if (ch == '<' || ch == '>') {
            fprintf(fp2, "\n%d\t%c\tRelational_operator\t%d", sl++, ch, line);
        } else if (ch == '(' || ch == '{') {
            fprintf(fp2, "\n%d\t%c\tOpening_braket\t%d", sl++, ch, line);
        } else if (ch == ')' || ch == '}') {
            fprintf(fp2, "\n%d\t%c\tClosing_braket\t%d", sl++, ch, line);
        } else if (ch == ';') {
            fprintf(fp2, "\n%d\t%c\tSemicolon\t%d", sl++, ch, line);
        }else if(ch=='%'){
            fprintf(fp2, "\n%d\t%c\tSepecial_operator\t%d", sl++, ch, line);
        } else if (isdigit(ch)) {
            lexeme[i++] = ch;
            flag = 0;
            ch1 = fgetc(fp1);
            if (ch1 == '.') {
                lexeme[i++] = ch1;
                flag = 1;
            } else {
                ungetc(ch1, fp1);
            }
        } else if (isalpha(ch)) {
            lexeme[i++] = ch;
            flag = 2;
        } else if (ch == '.') {
            if (i > 0 && flag == 0) {
                lexeme[i++] = ch;
                flag = 1;
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
