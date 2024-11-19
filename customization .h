//
// Created by User on 12.11.2024.
//

#ifndef CUSTOMIZATION_H
#define CUSTOMIZATION_H
#include <windows.h>

void setTextColor(const int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

#endif //CUSTOMIZATION_H
