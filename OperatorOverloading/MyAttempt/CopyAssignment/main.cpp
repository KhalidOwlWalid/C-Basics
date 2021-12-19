#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Mystring
{
private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    //Mystring(const Mystring &source);     
    ~Mystring();
    void get_text();
    Mystring &operator=(const Mystring &rhs);
    const char *get_str() const;
};

Mystring::Mystring()
    : str{nullptr}
    {
        str = new char[1];
        *str = '\0';
    }

Mystring::Mystring(const char *s)
    : str{nullptr}
    {
        if (s==nullptr)
        {
            str = new char[1];
            *str = '\0';
        }
        else
        {
            str = new char[std::strlen(s) + 1];
            strcpy(this->str, s);
        }
    }

// Mystring::Mystring(const Mystring &source) 
//     : str{nullptr} 
//     {
//         str = new char[std::strlen(source.str) + 1];
//         std::strcpy(str, source.str);
//     }
 
Mystring::~Mystring()
{
    delete [] str;
}

void Mystring::get_text()
{
    cout << *str << endl;
}

Mystring &Mystring::operator=(const Mystring &rhs)
{
    cout << "Copy Assignment" << endl;
    if (this==&rhs)
    {
        return *this;
    }
    delete [] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return *this;
}

const char *Mystring::get_str() const { return str; }

// Mystring &Mystring::operator=(const Mystring &rhs) {
//     std::cout << "Copy assignment" << std::endl;
//     if (this == &rhs)
//         return *this;
//     delete [] this->str;
//     str = new char[std::strlen(rhs.str) + 1];
//     std::strcpy(this->str, rhs.str);
//     return *this;
// }


int main()
{
    Mystring a {"Hello"};
    Mystring b;

    b = a;
    b.get_str();
    cout << b.get_str() << endl;

    b = "I love Alia";
    cout << b.get_str() << endl;

    return 0;
}