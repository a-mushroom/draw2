//2013-11-07 14:39
#include "token.h"

void display(enum TOKEN_TYPE type, char* str, int lineno)
{
    struct TOKEN temp;
    if (type == CONST_ID){
        double value;
        if(strcmp("PI", str) == 0)
            value = 3.1415926;
        else if(strcmp("E", str) == 0)
            value = 2.71828;
        else value = atof(str);
        //由于结构体不能像数组那样赋值，固新初始化一个结构体来赋给要输出的结构体
        struct TOKEN temp0={type, str, value, NULL, lineno};
        temp = temp0;}
    else if(type == FUNC){ 
        if(strcmp("SIN", str) == 0){
            struct TOKEN temp1={type, str, 0, sin, lineno};
            temp = temp1;}
        if(strcmp("COS", str) == 0){
            struct TOKEN temp2={type, str, 0, cos, lineno};
            temp = temp2;}
        if(strcmp("TAN", str) == 0){
            struct TOKEN temp3={type, str, 0, tan, lineno};
            temp = temp3;}
        if(strcmp("LN", str) == 0){
            struct TOKEN temp4={type, str, 0, log, lineno};
            temp = temp4;}
        if(strcmp("EXP", str) == 0){
            struct TOKEN temp5={type, str, 0, exp, lineno};
            temp = temp5;}
        if(strcmp("SQRT", str) == 0){
            struct TOKEN temp6={type, str, 0, sqrt, lineno};
            temp = temp6;}
        }
    else  {struct TOKEN temp7={type, str, 0, NULL, lineno}; temp = temp7;}
    printf("%4d, %12s, %12f, %12x, %4d\n", temp.type, temp.lexeme, temp.value, temp.func_ptr, temp.lineno);
    return;
}

