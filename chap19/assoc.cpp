#include <iostream>
#include <vector>
#include <utility>  

using namespace std;

struct Assoc{
    vector<pair<string,int> > vec;
    const int& operator[]( const string& s) const;
    int& operator[] (const string &s);
};

int& Assoc::operator[](const string& s){
    // search for s, return a reference to its value if found;
    // otherwise, make a new pair {s,0} and return a reference to its value
    for(int i = 0; i < vec.size(); i ++){
        if(s == vec[i].first) return vec[i].second;
    }
    vec.push_back({s,0});
    return vec.back().second;
}

int main(){
    Assoc value;
    string buff;
    while(cin >> buff) ++value[buff];
    
    for(auto x : value.vec){
        cout << x.first << ": " << x.second << endl;
    }
    
    return 0;
}