/**
 * @brief Decimal to Hex Stack
 *
 */
#include <stdio.h>
#include "SqStack.h"

char its_Hex(int x)
{
    switch (x)
    {
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    default:
        /*
            Existed error:
                return char(x) **this will return ASCII code 0~31 which will display NOTHING **
            fixed:
               return x+'0'
                
        */
        return x + '0';
    }
}

void exp1()
{
    // create a container to store the decimal number typed in
    int decNum ;
    printf("Please input a decimal number: ");
    scanf("%d", &decNum);

    // initialize a stack
    SqStack *stack;
    InitStack(stack);

    // store the Hex number per digit into the stack
    while (decNum)
    {
        Push(stack, its_Hex(decNum % 16));
        decNum /= 16;
    }

    // display the stack
    printf("the Hex number of what you typed is : ");
    DisplayStack(stack);
}