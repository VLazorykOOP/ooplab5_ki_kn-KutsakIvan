#include <iostream> 
//#include <string> 
#include <Windows.h>

using namespace std;

class String
{  
public:
    char* str;
    String()
    {
        str = new char[20];
        str[19] = '\0';
    }
    String(char* s)
    {
        int n = strlen(s);
        str = new char[n + 1];
        strcpy_s(str, strlen(s), s);
    }
    ~String()
    {
        delete[] str;
    }
    friend ostream& operator<<(ostream& output, const String& s);
    friend istream& operator>>(istream& input, String& s);
    String& operator=(const String& s);
    String(const String& s);
};

ostream& operator<<(ostream& output, const String& s)
{
    return output << s.str;
}

istream& operator>>(istream& input, String& s)
{
    return input >> s.str;
}

String& String::operator=(const String& s)
{
    if (this == &s)
        return *this;
    delete[] str;
    str = new char[strlen(s.str)+1];
    strcpy_s(str, strlen(s.str)+1, s.str);
    return *this;
}

String::String(const String& s)
{
    int length = strlen(s.str);
    str = new char[length + 1];
    strcpy_s(str, strlen(s.str), s.str);
}

class string_number : private String
{
    int number;
public:
    string_number(){ number = 0;}
    string_number(char* s, int n) : String(s){ number = n;}
    ~string_number()
    {
    }
    friend ostream& operator<<(ostream& output, const string_number& s);
    friend istream& operator>>(istream& input, string_number& s);
    string_number& operator=(const string_number& s);
    string_number(const string_number& s);
};

ostream& operator<<(ostream& output, const string_number& s)
{   
    return output << s.str << " " << s.number;
}

istream& operator>>(istream& input, string_number& s)
{
    return input >> s.str >> s.number;
}

string_number& string_number::operator=(const string_number& s)
{
    if (this == &s)
        return *this;
    String::operator=(s);
    number = s.number;
    return *this;
}

string_number::string_number(const string_number& s) : String(s)
{
    number = s.number;
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    String s_obj1, s_obj2;
    string_number obj1, obj2;
    cout << "Введіть рядок(s_obj1): "; cin >> s_obj1;
    cout << "Введіть рядок і число(obj1): "; cin >> obj1;
    cout << "\nВведений рядок(s_obj1): " << s_obj1;
    cout << "\nВведений рядок і число(obj1): " << obj1;
    
    cout << "\n===";
    s_obj2 = s_obj1;
    cout << "\ns_obj2 = s_obj1\ns_obj2: " << s_obj2;
    
    cout << "\n===";
    obj2 = obj1;
    cout << "\nobj2 = obj1\nobj2: " << obj2;
}