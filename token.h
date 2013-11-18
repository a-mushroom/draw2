/*
* 2013-11-06 11:17
*编译原理上机题,这个头文件里包含token的数据结构和符号表
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
#include <stdbool.h>

#define TOKEN_LEN 100

/*token的类别*/
enum TOKEN_TYPE
{
    KEYWORD,                            //保留字
    T,                                  //参数
    SEMICO,L_BRACKET,R_BRACKET,COMMA,   //分隔符
    PLUS,MINUS,MUL,DIV,POWER,           //运算符
    FUNC,                               //函数
    CONST_ID,                           //常数
    NONTOKEN,                           //空记号
    ERRTOKEN                            //出错记号
};

/*token数据结构*/
struct TOKEN
{
    enum TOKEN_TYPE type;
    char *lexeme;
    double value;
    double (*func_ptr)(double);
    int lineno;
};

/*区分token的符号表*/
static struct TOKEN tokentab[]=
{
    {CONST_ID,  "PI",   3.1415926,  NULL,   0},
    {CONST_ID,  "E",   2.71828,     NULL,   0},
    {T,         "T",    0.0,         NULL,   0},
    {FUNC,      "SIN",  0.0,         sin,   0},
    {FUNC,      "COS",  0.0,         cos,   0},
    {FUNC,      "TAN",  0.0,         tan,   0},
    {FUNC,      "LN",   0.0,         log,   0},
    {FUNC,      "EXP",  0.0,         exp,   0},
    {FUNC,      "SQRT", 0.0,        sqrt,   0},
    {KEYWORD, "ORIGIN", 0.0,        NULL,   0},
    {KEYWORD,  "SCALE", 0.0,         NULL,   0},
    {KEYWORD,    "ROT", 0.0,         NULL,   0},
    {KEYWORD,     "IS", 0.0,         NULL,   0},
    {KEYWORD,    "FOR", 0.0,         NULL,   0},
    {KEYWORD,   "FROM", 0.0,         NULL,   0},
    {KEYWORD,     "TO", 0.0,         NULL,   0},
    {KEYWORD,   "STEP", 0.0,         NULL,   0},
    {KEYWORD,   "DRAW", 0.0,         NULL,   0}
};
/*全局变量声明*/
FILE *in_file;           //源程序文件指针
unsigned int lineno;            //字符串所在行号
char token_buffer[TOKEN_LEN]; //字符缓冲区,保存从源程序中读取的字符串

/*词法分析相关函数*/

/*检查源程序文件是否存在,如果存在,打开该文件,并初始化lineno的值为1,返回true,否则返回false*/
extern bool init_scanner(const char *filename);

/*关闭源程序文件*/
extern void close_scanner(void);

/*获得源程序所有记号*/
//extern struct TOKEN get_token(void);
