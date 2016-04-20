#include <iostream>
using namespace std;

struct X{
    int i_;
    X(int i){
        cout << " constructor" << endl; 
        i_ = i;
    };
    X operator+(int rhs) { 
        cout << "x operator +" << endl;
        i_ += rhs; 
        return *this;
    }
};

struct Y{
    int i_;
    Y(X x) {
        i_ = x.i_;
    };
    Y operator+(Y  rhs)
    {
        cout << "y operator +" << endl;
        i_ += rhs.i_;
        return *this;
    }
};

int main(){
    
    X x=1;
    Y y = x;
    int i = 2;
    i + 10;
    x + 10;

    y + y;
    y + x;
    
    return 0;
}


