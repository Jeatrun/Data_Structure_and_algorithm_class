/**
 * @file Is_symmetry.h
 * @date 2023-10-18
 * Detect whether the given string is a symmetric string
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#include "SqStack.h"
#define str_SIZE 10
void exp3()
{
    // 1.create a string to store
    char str[str_SIZE];
    // 2.input the string
    printf("please enter a string:");
    scanf("%s", str);
    // 3.create a stack to store thr string
    SqStack *stack;
    InitStack(stack);
     int i = 0;
    while (str[i] != '\0' && i < str_SIZE) // Check if the character is '\0' before pushing it into the stack
    {
        Push(stack, str[i]);
        i++;
    }
    // 4.compair the stack from the top and the string from the first  to find whether is the same
    char pop_elem;
    /*for (int j = 0; j < i; j++) /
    {
        Pop(stack, pop_elem);
        if (pop_elem == '\0')
        {
            i--;
            continue;
        }
        else if (str[i] == '\0'){
            break;
        }
        else if (pop_elem != str[i])
            {
                printf("the string is not symmetry\n");
                return;
            }
    }
    printf("the string is symmetry\n");*/
    for (int j = 0; j < i; j++) // Use 'j' instead of 'i' here, and compare until 'j' equals 'i'
    {
        Pop(stack, pop_elem);
        if (pop_elem != str[j])
        {
            printf("the string is not symmetry\n");
            return;
        }
    }
    printf("the string is symmetry\n");
}