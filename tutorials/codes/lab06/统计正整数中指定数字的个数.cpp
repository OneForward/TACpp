#include <iostream>
using namespace std;

int CountDigit(int number, int digit)
{
    int cnt = 0;
    while (number) {
        if (number % 10 == digit) cnt++;
        number /= 10;
    }
    return cnt;
}

int main()
{
    int number, digit;
    cin >> number >> digit;
    cout << CountDigit(number, digit) << endl;
    return 0;
}
