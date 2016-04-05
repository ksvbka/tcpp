#include "intset.h"

int main()
{
    IntSet a({1,2,3,6,7,9});
    IntSet b({1,2,2,4,5,8,10});

    std::cout << Uinon(a,b);
    std::cout << Uinon(b,a);
    std::cout << Intersection(a,b);
    std::cout << Intersection(b,a);
    std::cout << Difference(a,b);
    std::cout << Difference(b,a);

    IntSet c;
    std::cout << Uinon(c,b);
    std::cout << Uinon(b,c);
    std::cout << Intersection(b,c);
    std::cout << Difference(b,c);

    return 0;
}
