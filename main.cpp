#include "CString.h"

int main()
{
    // // test all the functions in CString.h
    CString s1;
    CString s2("hello");
    CString s3(s2);
    CString s4("world");
    s1 = s2;
    s1 += s4;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s1[0] << endl;
    cout << s2[0] << endl;
    cin >> s1;
    cout << s1 << endl;
    // test operator!
    CString s5("h e  ll o  ");
    CString s6 = !s5;
    cout << s6 << endl;
    // test operator~
    CString s7("hello");
    s7.reverse();
    cout << !s7 << endl;
    return 0;
}