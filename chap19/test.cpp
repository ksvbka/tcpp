#include "String.h"
using namespace std;

int main(int argc, char const * argv[]) {
    String s{"I loved you but I did my best"};
    String x{s};
    String y{std::move(x)};

    y = s;
    x = std::move(y);

    char c = y[3];
    s = "I loved you but I did my best ver 2";
    cout << s << "\n";
    s += 'c';
    s += 'h';
    s += 'e';
    s += 'm';

    cout << s <<  "\n";
    String s2 = "Hell";
    s2 += " and high water";
    cout << s2 << '\n';
    String s3 = "qwerty";
    s3 = s3;
    String s4 = "the quick bro wn fox jumped over the lazy dog";
    s4 = s4;
    cout << s3 << " " << s4 << "\n";
    cout << s + ". " + s3 + String(". ") + "Horsefeathers\n";
    String buf;

    cout << "input a string: ";
    cin >> buf;
    cout << buf;
    while (cin >> buf && buf != "quit")
        cout << buf << " " << buf.size() << " " << buf.capacity() << '\n';

    return 0;
}
