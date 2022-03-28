#include "CString.h"

CString::CString()
{
    m_pString = new char[1];
    m_pString[0] = '\0';
}
CString::CString(const char *pString)
{
    m_pString = new char[strlen(pString) + 1];
    strcpy(m_pString, pString);
}
CString::CString(const CString &rhs)
{
    m_pString = new char[strlen(rhs.m_pString) + 1];
    strcpy(m_pString, rhs.m_pString);
}
CString::~CString()
{
    delete[] m_pString;
}
CString &CString::operator=(const CString &rhs)
{
    if (this != &rhs)
    {
        delete[] m_pString;
        m_pString = new char[strlen(rhs.m_pString) + 1];
        strcpy(m_pString, rhs.m_pString);
    }
    return *this;
}
CString &CString::operator=(const char *pString)
{
    delete[] m_pString;
    m_pString = new char[strlen(pString) + 1];
    strcpy(m_pString, pString);
    return *this;
}
CString &CString::operator+=(const CString &rhs)
{
    char *pTemp = new char[strlen(m_pString) + strlen(rhs.m_pString) + 1];
    strcpy(pTemp, m_pString);
    strcat(pTemp, rhs.m_pString);
    delete[] m_pString;
    m_pString = pTemp;
    return *this;
}
CString &CString::operator+=(const char *pString)
{
    char *pTemp = new char[strlen(m_pString) + strlen(pString) + 1];
    strcpy(pTemp, m_pString);
    strcat(pTemp, pString);
    delete[] m_pString;
    m_pString = pTemp;
    return *this;
}
char &CString::operator[](int index)
{
    return m_pString[index];
}
const char &CString::operator[](int index) const
{
    return m_pString[index];
}
ostream &operator<<(ostream &os, const CString &rhs)
{
    os << rhs.m_pString;
    return os;
}
istream &operator>>(istream &is, CString &rhs)
{
    char *pTemp = new char[256];
    is >> pTemp;
    rhs = pTemp;
    delete[] pTemp;
    return is;
}
bool operator==(const CString &lhs, const CString &rhs)
{
    return strcmp(lhs.m_pString, rhs.m_pString) == 0;
}
bool operator!=(const CString &lhs, const CString &rhs)
{
    return strcmp(lhs.m_pString, rhs.m_pString) != 0;
}
bool operator<(const CString &lhs, const CString &rhs)
{
    return strcmp(lhs.m_pString, rhs.m_pString) < 0;
}
bool operator>(const CString &lhs, const CString &rhs)
{
    return strcmp(lhs.m_pString, rhs.m_pString) > 0;
}
bool operator<=(const CString &lhs, const CString &rhs)
{
    return strcmp(lhs.m_pString, rhs.m_pString) <= 0;
}
bool operator>=(const CString &lhs, const CString &rhs)
{
    return strcmp(lhs.m_pString, rhs.m_pString) >= 0;
}

void CString::reverse()
{
    char *pTemp = new char[strlen(m_pString) + 1];
    strcpy(pTemp, m_pString);
    for (int i = 0; i < strlen(m_pString) / 2; i++)
    {
        m_pString[i] = pTemp[strlen(m_pString) - i - 1];
        m_pString[strlen(m_pString) - i - 1] = pTemp[i];
    }
    delete[] pTemp;
}
void CString::squeeze()
{
    // delete all unnecessary spaces
    char *pTemp = new char[strlen(m_pString) + 1];
    strcpy(pTemp, m_pString);
    int i = 0;
    int j = 0;
    while (pTemp[i] != '\0')
    {
        if (pTemp[i] != ' ' || (pTemp[i] == ' ' && pTemp[i - 1] != ' '))
        {
            m_pString[j] = pTemp[i];
            j++;
        }
        i++;
    }
    m_pString[j] = '\0';
    delete[] pTemp;
}

CString operator!(const CString &rhs)
{
    CString temp(rhs);
    temp.reverse();
    return temp;
}
CString operator~(const CString &rhs)
{
    CString temp(rhs);
    temp.squeeze();
    return temp;
}

CString operator+(const CString &lhs, const CString &rhs)
{
    CString temp(lhs);
    temp += rhs;
    return temp;
}
CString operator+(const CString &lhs, const char *pString)
{
    CString temp(lhs);
    temp += pString;
    return temp;
}
CString operator+(const char *pString, const CString &rhs)
{
    CString temp(pString);
    temp += rhs;
    return temp;
}
