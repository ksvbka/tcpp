/*  Hitogram class
    Authour: KR
*/
#include "histogram.h"
#include <iostream>
#include <vector>

using namespace std;

histogram::histogram(vector<int> interval) {
    interval_ = interval;
    count_ = vector<int>(interval.size() - 1, 0);
}

void histogram::count(vector<int> input) {
    for (auto element : input)
        for (int i = 0; i < interval_.size() - 1; ++i) {
            if (element > interval_[i] && element < interval_[i + 1])
                count_[i]++;
        }
}

void histogram::show() {
    for (int i = 0; i < interval_.size() - 1; ++i)
        cout << "Range " <<  i + 1 << ": [" << interval_[i] << ", " << interval_[i + 1] << "] : " <<  count_[i] << endl;
}
