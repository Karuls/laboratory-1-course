#include <iostream>
using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date {
    day dd;
    month mm;
    year yyyy;

    
    bool operator<(const Date& other) const {
        if (yyyy != other.yyyy) return yyyy < other.yyyy;
        if (mm != other.mm) return mm < other.mm;
        return dd < other.dd;
    }

    
    bool operator>(const Date& other) const {
        return other < *this;
    }

    // Перегрузка оператора ==
    bool operator==(const Date& other) const {
        return dd == other.dd && mm == other.mm && yyyy == other.yyyy;
    }
};

int main() {
    Date date1 = { 7, 1, 1980 };
    Date date2 = { 7, 2, 1993 };
    Date date3 = { 7, 1, 1980 };

    if (date1 < date2) cout << "True" << endl;
    else cout << "False" << endl;

    if (date1 > date2) cout << "True" << endl;
    else cout << "False" << endl;

    if (date1 == date2) cout << "True" << endl;
    else cout << "False" << endl;

    if (date1 == date3) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}
