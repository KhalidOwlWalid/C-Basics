#include <iostream>
#include <cstring>

class MyString
{
private:
    char *str;

public:
    MyString();
    MyString(const char *s);
    ~MyString();
    MyString &operator=(MyString &&rhs);

};

MyString::MyString()
{

}

MyString::MyString(const char *s)
    : str {nullptr}
{
    str = new char[std::strlen(s)+1];
    std::strcpy(str, s);
}

MyString::~MyString()
{
    if (str==nullptr)
    {
        std::cout << "Destructor called for : nullptr" << std::endl;
    }
    else
    {
        std::cout << "Destructor called for " << str << std::endl;
    }
}

MyString &MyString::operator=(MyString &&rhs)
{
    std::cout << "Move assignment called" << std::endl;
    if (this==&rhs)
    {
        return *this;
    }
    delete [] this->str;
    this->str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

int main()
{
    MyString a {"Hello"};
    a = MyString{"Hola"};
    a = "Bonjour";

    return 0;
}