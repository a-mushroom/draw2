/*2013-11-07 11:27
*编译原理上机作业，一个画图程序的词法分析
*/
%{
#include <stdio.h>
#include "token.h"

extern char *yytext;
extern FILE *yyin;
extern void display(enum TOKEN_TYPE, char*, int);
int sem_count = 0;
%}

/*规则定义部分*/
/*
(\/\/|--).*\n               //ignore comment;
[ \t\n]+                    //ignore whitespace;
;                           printf("SEMICO\t\t\";\"\t0.0\t\tNULL\n");
\(                          printf("L_BRACKET\t\"\(\"\t0.0\t\tNULL\n");
\)                          printf("R_BRACKET\t\")\"\t0.0\t\tNULL\n");
,                           printf("COMMA\t\t\",\"\t0.0\t\tNULL\n");
\+                          printf("PLUS\t\t\"+\"\t0.0\t\tNULL\n");
\-                          printf("MINUS\t\t\"-\"\t0.0\t\tNULL\n");
\*                          printf("MUL\t\t\"*\"\t0.0\t\tNULL\n");
\/                          printf("DIV\t\t\"/\"\t0.0\t\tNULL\n");
\*\*                        printf("POWER\t\"**\"\t0.0\t\tNULL\n");
PI                          printf("CONST_ID\tPI\t3.1415926\tNULL \n");
E                           printf("CONST_ID\tE \t2.71828\tNULL \n");
(SIN|COS|TAN|LN|EXP|SQRT)   printf("FUNC\t\t%s\t0.0\t\tNULL\n",yytext);
[a-zA-Z][a-zA-Z0-9]*        printf("T\t\t%s\t0.0\t\tNULL\n",yytext);
[0-9]+(\.[0-9]*)?           printf("CONST_ID\t\"%s\"\t\tNULL\n",yytext);
*/

%%
(\/\/|--).*\n               /*ignore comment*/;
[ \t\n]+                    /*ignore whitespace*/;
;                           display(SEMICO, yytext, yylineno);
\(                          display(L_BRACKET, yytext, yylineno);
\)                          display(R_BRACKET, yytext, yylineno);
,                           display(COMMA, yytext, yylineno);
\+                          display(PLUS, yytext, yylineno);
\-                          display(MINUS, yytext, yylineno);
\*                          display(MUL, yytext, yylineno);
\/                          display(DIV, yytext, yylineno);
\*\*                        display(POWER, yytext, yylineno);
T                           display(T, yytext, yylineno);
PI|E                        display(CONST_ID, yytext, yylineno);
SIN|COS|TAN|LN|EXP|SQRT     display(FUNC, yytext, yylineno);
ORIGIN|SCALE|ROT|IS|FOR|FROM|TO|STEP|DRAW display(KEYWORD, yytext, yylineno);
[a-zA-Z][a-zA-Z0-9]*        display(ERRTOKEN, yytext, yylineno);
[0-9]+(\.[0-9]+)*           display(CONST_ID, yytext, yylineno);
%%
int main(int avgs, char *avgr[])
{
    yyin = fopen(avgr[1], "r");
    if (yyin == NULL){
        printf("open file error!\n");
        return 1;}
    printf("类型           字符        值         函数指针    行号\n");
    printf("____________________________________________________________\n");
    yylex();
    printf("____________________________________________________________\n");
    fclose (yyin);
    return 0;
}
