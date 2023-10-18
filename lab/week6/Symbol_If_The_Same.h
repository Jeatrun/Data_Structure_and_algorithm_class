/**
 * @file Symbol_If_The_Same.h
 * @date 2023-10-17
 * @copyright Copyright (c) 2023
 * @details Detect if the input symbols match, if not, output a prompt and exit
 */
#include <stdio.h>
#include "SqStack.h"
#define str_SIZE 4
void exp2()
{
    // 1.create a string to compair
    char str[str_SIZE+1] ="^%&*";

    // 2.create a stack store what've typed in
    SqStack *stack;
    InitStack(stack);
    printf("please enter the string\n");
    char input[str_SIZE+1];
    scanf("%s", input);
    for (int i = 0; i < str_SIZE; i++)
    {
        Push(stack, input[i]);
    }
    // 3.compair the stack from the top and the string from the last char to find whether is the same
    char elem_pop;
    for (int i = str_SIZE-1; i >=0 ; i--)
    {
        Pop(stack, elem_pop);
        if (elem_pop != str[i])
        {
            // 4.if not,return false
            printf("Error: input is not correct, please try again\n");
            return;
        }
    }
    printf("paired successfully!");
}
