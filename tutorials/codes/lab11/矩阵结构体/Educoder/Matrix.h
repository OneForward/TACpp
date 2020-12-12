#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

// 设计你的 Matrix 类（或者结构体），
// 请使用运算符重载实现 乘法 和 流输出运算
// fpower 函数已经帮你实现了

const long long MOD = 1e9 + 7;

struct Matrix
{
    /* data */
};



Matrix fpower(Matrix x, long long n) {
    Matrix ans {1, 0, 0, 1}; // C++11 initializer list
    
    while (n) { 
        if (n % 2) ans *= x;
        x *= x;
        n /= 2;
    }
    return ans;
}

#endif