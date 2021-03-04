#if !defined(_COMPLEX_HPP_)
#define _COMPLEX_HPP_
#include <iomanip>

struct Complex
{
    int real, imag;

    Complex& operator+=(const Complex& rhs)
    {
        real += rhs.real;
        imag += rhs.imag;
        return *this; // 按引用返回结果
    }
 
    friend Complex operator+(Complex lhs, const Complex& rhs) 
    {
        lhs += rhs; // 复用复合赋值
        return lhs; // 按值返回结果（使用移动构造函数）
    }
    
    Complex& operator*=(const Complex& rhs)
    {
        real = real * rhs.real - imag * rhs.imag;
        imag = real * rhs.imag + imag * rhs.real;
        return *this; // 按引用返回结果
    }
 
    friend Complex operator*(Complex lhs, const Complex& rhs) 
    {
        lhs *= rhs; // 复用复合赋值
        return lhs; // 按值返回结果（使用移动构造函数）
    }
};

std::istream& operator>>(std::istream& is, Complex& obj) {
    is >> obj.real >> obj.imag;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Complex& obj)
{
    os << std::noshowpos << obj.real << std::showpos << obj.imag << "i";
    return os;
}

#endif // _COMPLEX_HPP_
