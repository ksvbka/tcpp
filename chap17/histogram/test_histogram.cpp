#include "histogram.h"
#include <iostream>

std::vector<int> input1{0, 2, 2, 4, 5, 2, 6, 5, 3, 3, 7, 8, 4, 7, 5, 7, 5, 6, 4, 4, 6};

std::vector<int> input2{0, 2, 2, 4, 5, 2, 6, 5, 3, 3, 7, 3, 5, 7, 4, 7, 8, 5, 4, 8, 8,\
                       8, 4, 7, 5, 7, 5, 6, 4, 4, 6};

int main(int argc, char const *argv[]) {
  histogram h({0, 3, 5, 7, 9});
  h.count(input1);
  h.show();

  h.count(input2);
  h.show();
  return 0;
}
