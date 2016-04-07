#ifndef __INT_SET_H__
#define __INT_SET_H__

#include <vector>
#include <iostream>

class IntSet {
  public:
    IntSet() : element_() {};
    IntSet(std::vector<int> init): element_(init) {};
    ~IntSet() {};

    std::vector<int> element() const;
    bool isMember(int i);
    bool isEmpty();
    void push_back(int i);

  private:
    std::vector<int> element_;
};

IntSet Uinon(IntSet a, IntSet b);
IntSet Intersection(IntSet a, IntSet b);
IntSet Difference(IntSet a, IntSet b);

std::ostream& operator<<(std::ostream& os, const IntSet a);

#endif
