#include <iostream>
using namespace std;

/********* Begin *********/
struct Complex
{
    float real, imag;
    
    Complex(float _r, float _i): real{_r}, imag{_i} {}

    Complex& operator+=(const Complex& rhs)
    {
        real += rhs.real;
        imag += rhs.imag;
    }

    Complex& operator-=(const Complex& rhs)
    {
        real -= rhs.real;
        imag -= rhs.imag;
    }
    
    Complex& operator*=(const Complex& rhs)
    {
        int real_copy = real;
        real = real * rhs.real - imag * rhs.imag;
        imag = real_copy * rhs.imag + imag * rhs.real;
    }
    
    void Print()
    {
        cout << noshowpos << real << showpos << imag << "i\n";
    }
};

Complex operator+(Complex lhs, const Complex& rhs) 
{
    lhs += rhs; 
    return lhs; 
}

Complex operator-(Complex lhs, const Complex& rhs) 
{
    lhs -= rhs; 
    return lhs; 
}

Complex operator*(Complex lhs, const Complex& rhs) 
{
    lhs *= rhs;
    return lhs; 
}
/********* End *********/

// 以下来自题目 run.cpp
int main()
{
    float a, b, c, d;
    cin >> a >> b >> c >> d;
    Complex c1(a, b), c2(c, d);

    cout << "c1 = ";
    c1.Print();
    cout << "c2 = ";
    c2.Print();

    cout << "c1 + c2 = ";
    (c1 + c2).Print();
    cout << "c1 - c2 = ";
    (c1 - c2).Print();
    cout << "c1 * c2 = ";
    (c1 * c2).Print();
}