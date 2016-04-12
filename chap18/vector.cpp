#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

template <class T>
class myVector {
 public:
  myVector(initializer_list<T> l);
  myVector(int size);
 private:
  vector<T> data_;
  int size_;
  template <class Type>
  friend ostream& operator<<(ostream& os , const myVector<Type>& v);
};
template <class T>
myVector<T>::myVector(int size) : data_(size), size_(size) {
  cout << "Init by an int value" << endl;
};

template <class T>
myVector<T>::myVector(initializer_list<T> l) {
  cout << "init by initializer list" << endl;
  for (auto i = l.begin(); i < l.end(); ++i)
    data_.push_back(*i);
  size_ = l.size();
}

template <class T>
ostream& operator<<(ostream& os , const myVector<T>& v) {
  os << "size: " << v.data_.size() << endl;
  for (int i = 0; i < v.size_; i++)
    os << v.data_[i] << " ";
  os << endl;
  return os;
}

int main(int argc, char const *argv[]) {
  myVector<int> v1{1, 2, 3, 12, 42, 234, 3};
  myVector<int> v2(5);
  myVector<int> v3 = 5;

  cout << v1;
  cout << v2;
  cout << v3;
  return 0;
}
