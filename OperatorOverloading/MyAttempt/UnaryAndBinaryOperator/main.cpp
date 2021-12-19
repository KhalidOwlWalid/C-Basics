#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &obj);
    friend std::istream &operator>>(std::istream &is, Mystring &rhs);

    private:
        char *str;

    public:
        Mystring();
        Mystring(const char *s);
        Mystring(const Mystring &source);
        void display();
        Mystring &operator=(Mystring &&rhs);

        
};

Mystring::Mystring()
    : str{nullptr}
{
    cout << "No args constructor" << endl;
}

Mystring::Mystring(const char *s)
    : str{nullptr}
    {
        str = new char[std::strlen(s)+1];
        std::strcpy(str, s);
        cout << "Args constructor for " << str << endl;
    }

Mystring::Mystring(const Mystring &source)
{
    this->str = new char [std::strlen(source.str) + 1 ];
    std::strcpy(this->str, source.str);
    cout << "Copy constructor for " << this->str << endl;
}

void Mystring::display()
{
    cout << str << endl;
}

Mystring &Mystring::operator=(Mystring &&rhs){
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] this->str;
    this->str = rhs.str;
    rhs.str = nullptr;
    return *this;
    
}

std::ostream &operator<<(std::ostream &os, const Mystring &obj)
{
    os << obj.str;
    return os;
}

std::istream &operator>>(std::istream &is, Mystring &rhs)
{
    char *buff = new char [1000];
    is >> buff;
    rhs = Mystring {buff};
    delete [] buff;
    return is;
}


int main()
{
    Mystring larry{"Larry"}; 
    Mystring moe{"Moe"};
    
    Mystring stooge = larry;
    // larry.display();                                                                      // Larry
    // moe.display();                                                                      // Moe
    
    // string a;

    // cin >> a;
    // cout << a << endl;
    cin >> larry;
    // cin >> larry.str;
    cout << larry << endl;

    return 0;                
}