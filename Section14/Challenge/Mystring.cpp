#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr}
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    //       std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source)
    : str(source.str)
{
    source.str = nullptr;
    //        std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring()
{
    delete[] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    //    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs)
{

    char buff[1000];
    in >> buff;
    rhs = Mystring{buff};
    return in;
}

Mystring Mystring::operator-() const
{
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); i++)
    {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring obj = Mystring{buff};
    delete[] buff;
    return obj;
}

bool Mystring::operator==(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring &rhs) const
{
    return !(*this == rhs);
}

bool Mystring::operator<(const Mystring &rhs) const
{
    return (rhs > *this);
}

bool Mystring::operator>(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) > 0);
}

Mystring Mystring::operator+(const Mystring &rhs) const
{
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring obj = Mystring{buff};
    delete[] buff;
    return obj;
}

Mystring Mystring::operator*(const int &rhs) const
{
    Mystring obj;
    for (size_t i = 1; i <= rhs; i++)
    {
        obj = obj + *this;
    }
    return obj;
}

Mystring &Mystring::operator+=(const Mystring &rhs)
{
    *this = *this + rhs;
    return *this;
}

Mystring &Mystring::operator*=(const int &rhs)
{
    *this = *this * rhs;
    return *this;
}

Mystring &Mystring::operator++()
{
    char *buff = new char[std::strlen(str) + 2];
    char addition[2]{"_"};
    std::strcpy(buff, str);
    std::strcat(buff, addition);
    *this = Mystring{buff};
    delete[] buff;
    return *this;
}

Mystring Mystring::operator++(int)
{
    Mystring temp(*this);
    operator++();
    return temp;
}
Mystring &Mystring::operator--()
{
    if (str != NULL)
    {
        const unsigned int length = strlen(str);
        if ((length > 0))
            str[length - 1] = '\0';
    }
    return *this;
}

Mystring Mystring::operator--(int)
{
    Mystring temp(*this);
    operator--();
    return temp;
}
