//
// Created by User on 12.11.2024.
//

#ifndef ARRAY_VALIDATION_H
#define ARRAY_VALIDATION_H
#include <stdio.h>
#include <stdbool.h>
#include "customization .h"

int validate_integer_value(const char *message)
{
    bool InvalidInput;
    int value = 0;
    printf("%s\n", message);
    do
    {
        if (scanf("%d", &value) != 1 || value < 1)
        {
            setTextColor(12);
            printf("Enter a positive integer value\n");
            setTextColor(7);
            fflush(stdin);
            InvalidInput = true;
        }
        else
            if (value == 0 || value > 100)
            {
                setTextColor(12);
                printf("[%d] doesn't lay in the estimated limit\n", value);
                setTextColor(7);
                fflush(stdin);
                InvalidInput = true;
            }
        else
        {
            fflush(stdin);
            InvalidInput = false;
        }
    }
    while(InvalidInput);
    return value;
}

bool validate_input(char *input, int symbols_size)
{
    if (strlen(input) > symbols_size)
    {
        setTextColor(12);
        printf("Invalid input\n");
        setTextColor(7);
        printf("[%s] consists of ", input);
        setTextColor(12);
        printf("%llu ", strlen(input));
        setTextColor(7);
        printf("characters\n");
        fflush(stdin);
        return false;
    }

    if (strchr(input, ' ') != NULL)
    {
        setTextColor(12);
        printf("Invalid input\n");
        setTextColor(7);
        printf("Input contains a space, which is not allowed: [%s]\n", input);
        fflush(stdin);
        return false;
    }

    input[strcspn(input, "\n")] = '\0';
    return true;
}
#endif //ARRAY_VALIDATION_H
