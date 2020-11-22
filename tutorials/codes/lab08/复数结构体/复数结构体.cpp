#include <iostream>
using namespace std;

/********* Begin *********/
struct Complex
{
    int real, imag;

    // add 成员函数, 调用时 x.add(y) 结果等价于 x += y
    void add(const Complex& rhs)
    {
        real += rhs.real;
        imag += rhs.imag;
    }
    
    // times 成员函数，调用时 x.times(y) 结果等价于 x *= y
    void times(const Complex& rhs)
    {
        int real_copy = real;
        real = real * rhs.real - imag * rhs.imag;
        imag = real_copy * rhs.imag + imag * rhs.real;
    }
    
    // 打印函数，成员函数，调用时 x.disp() 将打印 x 为 a + bi 的形式
    void disp()
    {
        cout << noshowpos << real << showpos << imag << "i\n";
    }
};

// add 函数，返回 lhs + rhs
Complex add(Complex lhs, const Complex& rhs) 
{
    lhs.add(rhs); 
    return lhs; 
}

// times 函数，返回 lhs * rhs
Complex times(Complex lhs, const Complex& rhs) 
{
    lhs.times(rhs); 
    return lhs; 
}
/********* End *********/


/********* 不需要修改 main 函数 *********/
int main()
{
    Complex x, y;

    cin >> x.real >> x.imag >> y.real >> y.imag;

    cout << "x = "; x.disp();
    cout << "y = "; y.disp();

    x.add(y); // x += y
    
    cout << "x += y; x = ";
    x.disp(); // 打印 x;

    y.times(x); // y *= x;
    
    cout << "y *= x; y = ";
    y.disp(); // 打印 y;

    cout << "x + y = ";
    add(x, y).disp(); 

    cout << "y * x = ";
    times(y, x).disp(); 

    cout << "x = "; x.disp();
    cout << "y = "; y.disp();


    return 0;
}
