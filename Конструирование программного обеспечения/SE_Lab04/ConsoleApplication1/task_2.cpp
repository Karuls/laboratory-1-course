#include <iostream>
#include <string>
using namespace std;

typedef unsigned short index;
typedef string country;
typedef string town;
typedef string street;
typedef unsigned short house_number;
typedef unsigned short corpyc;
typedef unsigned short flat;
typedef string owner;

struct Data {
    index in;
    country cc;
    town tt;
    street st;
    house_number hn;
    corpyc cp;
    flat ff;
    owner ow;

    bool operator>(const Data& other) const {
        return in > other.in;
    }

 
    bool operator==(const Data& other) const {
        return in == other.in && cc == other.cc && tt == other.tt && st == other.st && hn == other.hn && cp == other.cp && ff == other.ff && ow == other.ow;
    }
};

int main() {
    Data data1 = { 23100, "BEL", "Lida", "Oct", 21, 2, 1210, "Anna" };
    Data data2 = { 23100, "BEL", "Lida", "Oct", 21, 2, 1210, "Anna" };
    Data data3 = { 244, "RUS", "Diva", "Cent", 44, 1, 80, "Alan" };
    Data data4 = { 23124, "POL", "Xita", "Mins", 11, 4, 410, "Tom" };

    if (data3 > data4)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    if (data1 == data2)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
