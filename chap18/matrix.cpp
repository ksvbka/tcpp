/*Simple implement matrix class - 17.5.2 - The C++ programming*/
/* Author: TrungKien                                          */

#include <iostream>
#include <array>
#include <stdexcept>  // To use runtime_error()
#include <memory>     // To use uninitialized_copy() and copy()
#include <algorithm> // To use swap() - until C_++11
#include <utility> // To use swap() - since C++11

// using namespace std;

template <class T>
class Matrix{
public:
  Matrix(int d1, int d2) : dim{d1,d2}, elem{new T[d1*d2]} {}
  int size() const { return dim[0] * dim[1];}

  Matrix(const Matrix& rhs); // Copy constructor
  Matrix(Matrix&& rhs);      // Move constructor

  Matrix& operator=(const Matrix& rhs); // Copy asignment
  Matrix& operator=(Matrix&& rhs);      // Move asignment

  ~Matrix(){ elem = nullptr;}
private:
  std::array<T,2> dim;
  T* elem; // Pointer to sz element of type T
  friend std::ostream& operator << (std::ostream& os, const Matrix<T>& rhs){
    for(int i = 0; i < rhs.dim[0]; i++){
      for(int j = 0; j < rhs.dim[1]; j++){
        os << "\t" << rhs.elem[i * rhs.dim[0] + j];
      }
      os << "\n";
    }
    return os;
  }

};

// Copy constructor
template <class T>
Matrix<T>::Matrix(const Matrix<T>& rhs): dim(rhs.dim), elem{new T[rhs.size()]}{
  std::cout << "Copy constructor" << std::endl;
  std::uninitialized_copy(rhs.elem, rhs.elem + rhs.size(), elem); // copy elemement
}

// Move constructor
template<class T>
Matrix<T>::Matrix(Matrix<T>&& rhs): dim(rhs.dim), elem(rhs.elem) {
  std::cout << "Move constructor" << std::endl;
  rhs.dim = {0,0};
  rhs.elem = nullptr;
}

// Copy asignment
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs){
  std::cout << "Copy assignment" << std::endl;
  if(dim[0] != rhs.dim[0] || dim[1] != rhs.dim[1])
    throw std::runtime_error("Bad size in Matrix = ");
  std::copy(rhs.elem, rhs.elem + rhs.size(), elem);
  return *this;
}

// Move assignment
template <class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& rhs){
  std::cout << "Move assignment" << std::endl;
  swap(dim, rhs.dim);
  swap(elem, rhs.elem);
  return *this;
}


int main(int argc, char const *argv[])
{
  int size = 1000;
  int loop = 1000;

  Matrix<int> m1 = Matrix<int>(size,size);
  Matrix<int> m2 {m1};
  Matrix<int> m3 {m1};

  for(int i = 0; i < loop; i++)
  {
    /*Ver1: use copy assignment: time ~8s*/
    // m1 = m2;
    // m2 = m3;
    // m3 = m1;

    /*Ver 2: use move assiment: time ~0.037s*/
    m1 = std::move(m2);
    m2 = std::move(m3);
    m3 = std::move(m1);
  }

  return 0;
}
