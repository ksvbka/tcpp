/*  Hitogram class
    Authour: KR
*/

#ifndef __HISTOGRAM_H__
#define __HISTOGRAM_H__

#include <vector>
// TODO: Modify to generic

class histogram
{
public:
    histogram(std::vector<int> inteval);
    void count(std::vector<int> input);
    void show();


    /* data */
private:
    std::vector<int> count_;
    std::vector<int> interval_;

};


#endif
