
#include <iostream>
using namespace std;
class complex
{
    int a, b;

public:
    void input(int q, int w)
    {
        a = q;
        b = w;
    }
    void process(complex o1, complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }
    void print()
    {
        cout << " Complex number is: " << a << " + " << b << "i" << endl;
    }
};
int main()
{
    int a, b, x, y;
    complex t, g, u;
    cout << " Enter 1st complex number real" << endl;
    cin >> a;
    cout << " Enter 1st complex number imaginary" << endl;
    cin >> b;
    cout << " Enter 2nd complex number real" << endl;
    cin >> x;
    cout << " Enter 2nd complex number imaginary" << endl;
    cin >> y;
    t.input(a, b);
    t.print();
    g.input(x, y);
    g.print();
    u.process(t, g);
    u.print();
    return 0;
}