#include <iostream>
#include <cstring>

using namespace std;

class Mystring
{

    private:
        char *str;

    public:
        Mystring();
        Mystring(const char *s);
        ~Mystring();
        const char *get_str() const;
        Mystring &operator=(const Mystring &rhs);
        Mystring(const Mystring &source);
};

Mystring::Mystring()
    : str{nullptr}
    {
        cout << "No-args constructor" << endl;
    }

Mystring::Mystring(const char *s)
    : str{nullptr}
    {
        cout << "Args constructor" << endl;
        if (s==nullptr)
        {
            str = new char[1];
            *str = '\0';
        }
        else
        {
            str = new char[strlen(s) + 1];
            strcpy(this->str, s);
        }
    }

Mystring::~Mystring()
{
    delete [] str;
}

const char *Mystring::get_str() const 
{
    return str;
}

Mystring::Mystring(const Mystring &source)
{
    str = new char [strlen(source.str) + 1];
    strcpy(this->str, source.str);
}

Mystring &Mystring::operator=( const Mystring &rhs)
{
    if (this==&rhs)
    {
        return *this;
    }
    delete [] str;
    str = new char [strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return *this;
}

int main()
{
    Mystring greetings {"Hello"};
    Mystring say_something {"I am Khalid"};
    Mystring from_alia {greetings};

    cout << say_something.get_str() << endl;

    say_something = greetings;

    cout << say_something.get_str() << endl;

    say_something = "It is a nice weather isnt it";
    cout << say_something.get_str() << endl;

    return 0;
}