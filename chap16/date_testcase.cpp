#include <iostream>
#include "date.h"

using namespace std;
using namespace kr;

int main(int argc, char const *argv[])
{
    date date1(28,2,2016);
    cout << date1;

    cout << ++date1;
    cout << --date1;
    cout << date1++;
    cout << date1--;

    date date3(20050101);

    cout << date3--;
    cout << date1++;

    cout << "is date2 == date3 :" << ((date1 == date3) ? "true" : "false") << endl;
    cout << "is date2 <  date3 :" << ((date1  < date3) ? "true" : "false")<< endl;
    cout << "is date2 >  date3 :" << ((date1 > date3)  ? "true" : "false") << endl;
    cout << "is date2 >= date3 :" << ((date1 >= date3) ? "true" : "false")<< endl;
    cout << "is date2 <= date3 :" << ((date1 <= date3) ? "true" : "false")<< endl;
    cout << "is date2 != date3 :" << ((date1 != date3) ? "true" : "false")<< endl;

    return 0;
}
