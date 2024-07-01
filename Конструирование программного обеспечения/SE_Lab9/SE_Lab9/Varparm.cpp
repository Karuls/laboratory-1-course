#include "Varparm.h"
#include <iostream>
using namespace std;
using namespace Varparm;

int main()
{
    int rez1 = ivarparm(1, 5);
    int rez2 = ivarparm(2,11,2);
    int rez3 = ivarparm(3, 5, 6, 7);
    int rez4 = ivarparm(7, 11, 12, 13, 14, 15, 16,17);

    int srez1 = svarparm(1, 10);
    int srez2 = svarparm(2, 10, 11);
    int srez3 = svarparm(3, 10, 11, 12);
    int srez4 = svarparm(3, 11, 12, 13, 14, 15, 16, 17);

    
    double max_float = FLT_MAX;
    double F_rez1 = fvarparm(1, 4.8, max_float);
    double F_rez2 = fvarparm(3, 4.8, 5.8, max_float);
    double F_rez3 = fvarparm(4, 4.8, 5.8, 6.8, max_float);
    double F_rez4 = fvarparm(8, 4.8, 5.8, 6.8, 7.8, 8.8, 9.8,10.8, max_float);

    double max_double = DBL_MAX;
    double D_rez1 = dvarparm(2, 4.8, max_double);
    double D_rez2 = dvarparm(3, 4.8, 5.8, max_double);
    double D_rez3 = dvarparm(4, 4.8, 5.8, 6.8, max_double);
    double D_rez4 = dvarparm(8, 4.8, 5.8, 6.8, 7.8, 8.8, 9.8, 10.8, max_double);
    
}
