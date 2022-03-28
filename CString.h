#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>
#include <cstring>

using namespace std;

class CString
{
public:
    CString();
    CString(const char *);
    CString(const CString &);
    ~CString();

    CString &operator=(const CString &);
    CString &operator=(const char *);
    CString &operator+=(const CString &);
    CString &operator+=(const char *);
    char &operator[](int);
    const char &operator[](int) const;
    void reverse();
    void squeeze();

    friend CString operator!(const CString &);
    friend CString operator~(const CString &);

    friend ostream &operator<<(ostream &, const CString &);
    friend istream &operator>>(istream &, CString &);
    friend bool operator==(const CString &, const CString &);
    friend bool operator!=(const CString &, const CString &);
    friend bool operator<(const CString &, const CString &);
    friend bool operator>(const CString &, const CString &);
    friend bool operator<=(const CString &, const CString &);
    friend bool operator>=(const CString &, const CString &);

    friend CString operator+(const CString &, const CString &);
    friend CString operator+(const CString &, const char *);
    friend CString operator+(const char *, const CString &);
    

private:
    char *m_pString;
};

#endif