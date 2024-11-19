#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "array_validation.h"
#include "sort_method.h"
#include "customization .h"

int main()
{
    do
    {
        int lines_size = 0, symbols_size = 0;
        srand(time(NULL));
        printf("This program sorts the array of symbols by the standard ASCII table\n");

        lines_size = validate_integer_value("Enter the number of lines [1 - 100]:");
        symbols_size = validate_integer_value("Enter the number of symbols in a string [1 - 100]:");

        char arr[lines_size][symbols_size + 1] = {};
        char *address[lines_size] = {};
        for (int i = 0; i < lines_size; i++)
        {
            address[i] = arr[i];
        }

        printf("Choose array generating method:\n");
        printf("1 - By hands\n");
        printf("2 - Random\n");

        int generating = 0;
        do
        {
            generating = getch();
            while (getchar() != '\n');
            switch (generating)
            {
                case 49:
                    printf("Enter the strings:\n");
                    printf("The estimated limit for symbols is: ");
                    setTextColor(2);
                    printf("%d\n", symbols_size);
                    setTextColor(7);

                    bool InvalidString = true;
                    for (int i = 0; i < symbols_size + 1; i++)
                    {
                        do
                        {
                            printf("%d string ->", i + 1);
                            fgets(arr[i], symbols_size + 2, stdin);
                            arr[i][strcspn(arr[i], "\n")] = '\0';
                            InvalidString = !validate_input(arr[i], symbols_size);
                        }
                        while (InvalidString);
                    }
                    print_array(address, lines_size, "\nBy hands array before sorting:");
                    break;

                case 50:
                    for (int i = 0; i < lines_size; i++)
                    {
                        generate_random_string(address[i], symbols_size);
                    }
                    print_array(address, lines_size, "\nRandomly generated array before sorting:");
                    break;

                default:
                    setTextColor(12);
                    printf("Invalid input\nYou can only choose between numbers 1 and 2\n");
                    setTextColor(7);
            }
        }
        while (generating != 49 && generating != 50);

        printf("\nChoose array sorting method:\n");
        printf("1 - Descending sorting\n");
        printf("2 - Ascending sorting\n");
        int sorting = 0;
        sorting = getch();

        do
        {
            switch (sorting)
            {
                case 49:
                    descending_array_sort(address, lines_size);
                    print_array(address, lines_size, "Array after descending sorting method:");
                    break;
                case 50:
                    ascending_array_sort(address, lines_size);
                    print_array(address, lines_size, "Array after descending sorting method:");
                    break;
                default:
                    setTextColor(12);
                    printf("Invalid input\nYou can only choose between 1 and 2\n");
                    setTextColor(7);
            }
            /*while (getchar() != '\n');
            sorting = getch();*/
        }
        while (sorting != 49 && sorting != 50);
        printf("To restart the program press ");
        setTextColor(2);
        printf("ENTER");
        setTextColor(7);
        printf(", otherwise press any key to exit\n");
        while (getchar() != '\n');
    }
    while (getch() == 13);
    return 0;
}
