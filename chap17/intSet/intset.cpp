#include "intset.h"
using namespace std;

vector<int> IntSet::element() const
{
    return element_;
}

bool IntSet::isMember(int i)
{
    for(auto e : element_)
        if(i == e) return true;
    return false;
}

bool IntSet::isEmpty()
{
    return element_.empty();
}

void IntSet::push_back(int i)
{
    element_.push_back(i);
}

IntSet Uinon(IntSet a, IntSet b)
{
    IntSet ret{};
    for(auto i : a.element())
        if(b.isMember(i))
            ret.push_back(i);
    return ret;
}

IntSet Intersection(IntSet a, IntSet b)
{
    IntSet ret{a};
    for(auto i : b.element())
        if(!a.isMember(i))
            ret.push_back(i);
    return ret;
}

IntSet Difference(IntSet a, IntSet b)
{
    IntSet ret{};
    for(auto i : a.element())
        if(!b.isMember(i))
            ret.push_back(i);
    for(auto j : b.element())
        if(!a.isMember(j))
            ret.push_back(j);
    return ret;
}

ostream& operator<<(ostream& os, const IntSet a)
{
    for(auto i : a.element())
        os << i << " " ;
    os << endl;
}
