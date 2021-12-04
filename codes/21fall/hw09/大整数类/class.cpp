#include "class.h"

istream& operator>> (istream& is, BigInteger& x) {
    char s[1005]; 
    is.getline(s, sizeof(s));

    int len = 0;
    while (s[len]) len++;
    x.len = len;
    for (int i = 0; i < len; ++i) { 
        x.data[i] = s[len-1-i] - '0';
    }
    return is;
}

ostream& operator<< (ostream& os, const BigInteger& x) {
    for (int i = x.len-1; i >= 0; --i) { 
        os << x.data[i];
    }
    return os;
}

BigInteger& BigInteger::operator+= (const BigInteger& rhs) {
    int carry = 0, sum; len = max(len, rhs.len);
    for (int i = 0; i <= len; ++i) { 
        sum = data[i] + rhs.data[i] + carry;
        carry = sum / 10;
        if (sum >= 10) sum -= 10;
        data[i] = sum;
    }
    if (data[len]) len++;
    return *this;
}

BigInteger operator+ (BigInteger x, const BigInteger& y) {
    x += y;
    return x;
}
