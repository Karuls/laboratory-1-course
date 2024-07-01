#include<iostream>
#include <cstdarg>
namespace Varparm {
    int ivarparm(int count, ...) {
        int result = 1;
        va_list args;
        va_start(args, count); 

        // Умножаем значения всех параметров, начиная со второго
        for (int i = 0; i < count; ++i) {
            if (i != 0) {
                int value = va_arg(args, int);
                result *= value;
            }
            else {
                va_arg(args, int);
            }
        }

        va_end(args); 
        return result;
    }
	int svarparm(short count, ...) {
        int max_value = 0; bool flag = false;
        va_list args;
        va_start(args, count);

        
        for (int i = 0; i < count; ++i) {
            if (i != 0) {
                int value = va_arg(args, int);
                if (!flag) int max_value = va_arg(args, int); flag = true;
                if (value > max_value) max_value = value;
            }
            else {
                va_arg(args, int);
            }
        }

        va_end(args);
        return max_value;
	}

    double fvarparm(int count, ...) {
        double sum = 0.0;
        va_list args;
        va_start(args, count); 

        
        for (int i = 0; i < count - 1; ++i) {
            float value = va_arg(args, double);
            sum += value;
        }

        va_end(args);
        return sum;
    }

    double dvarparm(int count, ...) {
        double sum = 0.0;
        va_list args;
        va_start(args, count); 
         
        for (int i = 0; i < count - 1; ++i) {
            double value = va_arg(args, double); 
            sum += value;
        }

        va_end(args); 
        return sum;
    }
}