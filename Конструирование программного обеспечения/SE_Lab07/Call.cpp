#include <iostream>
#include "Call.h"
using namespace Call;
int main() {
    
    int c1 = сdecl(1, 2, 3);
    int x = 4, y = 4, z = 1;
    int c2 = stdcall(x, y, z);
    int c3 = fastcall(4, 1, 2, 5);

    return 0;
}



