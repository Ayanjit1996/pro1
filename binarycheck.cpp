//check for binary string

#include <iostream>
#include <string.h>
using namespace std;

class binarycheck
{
    string s;

public:
    void input(void);
    void check(void);
    void ones_c(void);
    void display(void);
};

void binarycheck::input(void)
{
    cout << " Enter a binary string " << endl;
    cin >> s;
}

void binarycheck::check(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "\nITS NOT A BINARY STRING" << endl;
            exit(0);
        }
    }
}

void binarycheck::ones_c(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '1')
            s.at(i) = '0';
        else
            s.at(i) = '1';
    }
}

void binarycheck::display(void)
{
    cout << " Diplaying your binary" << endl;
    for (int i = 0; i < s.length(); i++)
        cout << s.at(i);
    cout << endl;
}

int main()
{
    binarycheck c;
    c.input();
    c.display();
    c.check();
    c.ones_c();
    c.display();
    return 0;
}