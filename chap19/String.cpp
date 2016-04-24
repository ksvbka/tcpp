#include "String.h"
#include <cstring>

/* Ancillary function*/

/* Expand into free store*/
char* expand(const char* ptr, int n) {
    char* p = new char[n];
    strcpy(p, ptr);
    return p;
}
/* Copy operations go give a String a copy of the members of another */
void String::copy_from(const String& x) {
    if (x.sz <= short_max) {
        memcpy(this, &x, sizeof(x));
        ptr = ch;
    } else {
        ptr = expand(x.ptr, x.sz + 1);
        sz = x.sz;
        space = 0;
    }
}

void String::move_from(String& x) {
    if (x.sz <= short_max) {
        memcpy(this, &x, sizeof(x));
        ptr = ch;
    } else {
        ptr = x.ptr;
        sz = x.sz;
        space = x.space;
        x.ptr = x.ch; // x = ""
        x.sz = 0;
        x.ch[0] = 0;
    }
}

String::String() : sz{0}, ptr{ch} {
    ch[0] = 0; // Terminating 0
}

String::String(const char* p)
    : sz{strlen(p)}, ptr{sz <= short_max ? ch : new char[sz + 1]}, space{0} {
    strcpy(ptr, p);
}

String::String(const String& x) {
    copy_from(x);
}

String::String(String&& x) {
    move_from(x);
}

// // NOTE: operator= like copy_from but it have to delete any free store
// // owned by target and make sure it does not get into trouble with self-assignment

String& String::operator=(const String& x) {
    if (this == &x) return *this; // Deal with self-assignment
    char* p = (short_max < sz) ? ptr : 0;
    copy_from(x);
    delete[] p;
    return *this;
}

String& String::operator=(String&& x) {
    if (this == &x) return *this;
    if (short_max < sz) delete[] ptr;
    move_from(x);
    return *this;
}

String& String::operator+=(char c) {
    if (sz == short_max) {
        int n = sz + sz + 2;
        ptr = expand(ptr, n);
        space =  n - sz - 2;
    } else if (short_max  < sz) {
        if (space == 0) {
            int n = sz + sz + 2;
            char* p = expand(ptr, n);
            delete[] ptr;
            ptr = p;
            space = n - sz - 2;
        } else
            --space;
    }
    ptr[sz] = c;
    ptr[++sz] = 0;
    return *this;
}

/* Helper funciton */
std::ostream& operator<<(std::ostream& os, const String s) {
    return os << s.c_str();
}

std::istream& operator>>(std::istream& is, String& s) {
    s = "";
    char ch;
    while (is.get(ch) && !isspace(ch)){
        s += ch;
    }
    return is;
}

bool operator==(const String& a, const String& b) {
    if (a.size() != b.size())
        return false;
    for (int i = 0; i != a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}
bool operator!=(const String& a, const String& b) {
    return !(a == b);
}

// Helper function for support rang-for: begin() and end()
char* begin(String &x) {
    return x.c_str();
}
char* end(String& x) {
    return x.c_str() + x.size();
}
const char* begin(const String& x) {
    return x.c_str();
}
const char* end(const String& x) {
    return x.c_str() + x.size();
}

String& operator+=(String& a, const String & b) {
    for (auto x : b)
        a += x;
    return a;
}
String operator+(const String & a, const String & b) {
    String res{a};
    res += b;
    return res;
}

String operator"" _s(const char* p, size_t) {
    return String{p};
}


/*Test*/

// #include "String.h"
// using namespace std;

// int main(int argc, char const * argv[]) {
//     String s{"I loved you but I did my best"};
//     String x{s};
//     String y{std::move(x)};

//     y = s;
//     x = std::move(y);

//     char c = y[3];
//     s = "I loved you but I did my best ver 2";
//     cout << s << "\n";
//     s += 'c';
//     s += 'h';
//     s += 'e';
//     s += 'm';

//     cout << s <<  "\n";
//     String s2 = "Hell";
//     s2 += " and high water";
//     cout << s2 << '\n';
//     String s3 = "qwerty";
//     s3 = s3;
//     String s4 = "the quick bro wn fox jumped over the lazy dog";
//     s4 = s4;
//     cout << s3 << " " << s4 << "\n";
//     cout << s + ". " + s3 + String(". ") + "Horsefeathers\n";
//     String buf;

//     cout << "input a string: ";
//     cin >> buf;
//     cout << buf;
//     while (cin >> buf && buf != "quit")
//         cout << buf << " " << buf.size() << " " << buf.capacity() << '\n';

//     return 0;
// }
