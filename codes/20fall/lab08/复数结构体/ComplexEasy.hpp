#if !defined(_COMPLEX_EASY_HPP_)
#define _COMPLEX_EASY_HPP_

#include <iostream>
#include <iomanip>

/********* Begin *********/

struct Complex
{
    int real, imag;

    // add 成员函数
    void add(const Complex& rhs)
    {
        real += rhs.real;
        imag += rhs.imag;
    }
    
    // times 成员函数
    void times(const Complex& rhs)
    {
        real = real * rhs.real - imag * rhs.imag;
        imag = real * rhs.imag + imag * rhs.real;
    }
    
    // 打印函数，成员函数
    void disp()
    {
        std::cout << std::noshowpos << real << std::showpos << imag << "i\n";
    }
};

// add 函数
Complex add(Complex lhs, const Complex& rhs) 
{
    lhs.add(rhs); 
    return lhs; 
}

// times 函数
Complex times(Complex lhs, const Complex& rhs) 
{
    lhs.times(rhs); 
    return lhs; 
}

/********* End *********/

#endif // _COMPLEX_EASY_HPP_
