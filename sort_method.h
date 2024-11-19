//
// Created by User on 12.11.2024.
//

#ifndef SORT_H
#define SORT_H
#include <string.h>

void descending_array_sort(char **array, const int num)
{
    for (int i = 0; i < num - 1; i++)
        for (int j = i + 1; j < num; j++)
            if (strcmp(array[i], array[j]) < 0)
            {
                char *temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

void ascending_array_sort(char **array, const int num)
{
    for (int i = 0; i < num - 1; i++)
        for (int j = i + 1; j < num; j++)
            if (strcmp(array[i], array[j]) > 0)
            {
                char *temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

char random_char(const int range_min, const int range_max)
{
    char generated_char = range_min + rand() % (range_max - range_min + 1);
    if (generated_char > 90 && generated_char < 97)
    {
        generated_char += 6;
    }
    return generated_char;
}

void generate_random_string(char *str, const int length)
{
    for (int i = 0; i < length; i++)
    {
        str[i] = random_char(65, 122);
    }
    str[length] = '\0';
}

void print_array(char **array, const int size, const char *message)
{
    setTextColor(2);
    printf("%s\n", message);
    setTextColor(7);
    for (int i = 0; i < size; i++)
    {
        setTextColor(2);
        printf("%d -> %s\n", i + 1, array[i]);
        setTextColor(7);
    }
}
#endif //SORT_H
