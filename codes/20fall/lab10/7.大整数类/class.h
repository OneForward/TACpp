#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <iostream>
using namespace std; // not recommended

// 1. 规模限定 2. 非负整数
class BigInteger
{
    int data[1005]{}, len = 0; // C++11 non-static member initialization
    // notice that array can be carefully copied by compiler, thus copy contructor may not be necessary;

public:

    friend istream& operator>> (istream& is, BigInteger& x);

    friend ostream& operator<< (ostream& os, const BigInteger& x);

    BigInteger& operator+= (const BigInteger& rhs) ;

    friend BigInteger operator+ (BigInteger x, const BigInteger& y);

};



#endif /* CLASS_H */