/*
 Simple String class that implements the short string optimization
 size() = sz is the number of elements;
 if size() < shor_max, the charactors are held in the String object itself
 otherwise the free store is used.

 ptr points to the start of the charactor sequence
 the character sequence is kept zero-terminated: ptr[size()] == 0;
 this allows us to use C library string functions and to easily return a C-style
 string c_str()

 To allow efficient addition of characters at the end, String grows by doubling
 its allocation, capacity() is the amount of space available for characters
 (excluding the terminating 0): sz + space
*/
#include <stdexcept>
#include <exception>
#include <iostream>

class String {
  public:
    String();
    ~String() { if (short_max < sz) delete[] ptr;}


    String (const char* p);    // Constructor from C-style string
    String(const String&);              // Copy constructor
    String& operator=(const String&);   // Copy assingment
    String(String&& x);                 // Move constructor
    String& operator=(String&& x);      // Move assignment

    // /* Access element*/
    char& operator[](int n) { return ptr[n]; }      // Unchecked element access
    char  operator[](int n) const { return ptr[n]; }

    char& at(int n){ check(n); return ptr[n];}      // Rang-checked element acces
    char  at(int n) const { check(n); return ptr[n];}

    // /* Operator */
    String& operator+=(char c);         // Add c at end
    char* c_str() { return ptr;}  // C-style string acces
    const char* c_str() const { return ptr;}

    int size() const { return sz;}      // Number of elements
    int capacity() const                // Element + available space
    { return (sz <= short_max) ? short_max : sz + space;}
private:
    static const int short_max = 15;
    unsigned int sz;     // Number of characters;
    char* ptr;
    union{
        int space;  // unused allocated space;
        char ch[short_max + 1]; // Leave space for terminaling 0
    };

    // range check
    void check(int n) const {
        if(n < 0 || sz <= n)
            throw std::out_of_range("String::at()");
    }

    void copy_from(const String& x);
    void move_from(String& x);

};

/* Helper funciton */
//
std::ostream& operator<<(std::ostream& os, const String s);
std::istream& operator>>(std::istream& is, String& s);
bool operator==(const String& a, const String& b);
bool operator!=(const String& a, const String& b);
String& operator+=(String& a, const String & b);
String operator+(const String & a, const String & b);
String operator"" _s(const char* p, size_t);
