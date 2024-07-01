#include "stdafx.h"
#include "function2.h"
#include <iostream>


int calculate_birthday(int year, int number, int day, int month, int months1[], int months2[]) {
    if (year % 4 == 0) {
        for (int i = 0; i < month - 1; i++) {
            number += months2[i];
        }
        number += day;
    }
    else {
        for (int i = 0; i < month - 1; i++) {
            number += months1[i];
        }
        number += day;
    }
    std::cout << "Порядковый номер введенного дня в году: " << number << std::endl;
    return number;
}