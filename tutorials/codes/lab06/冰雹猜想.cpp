#include<iostream>
using namespace std;

void validate(int n) {
    cout << n << " ";

    if (n == 1) return;
    if (n % 2 == 0) validate(n / 2);
    else validate(n * 3 + 1);
}

int main()
{
    int n; cin >> n;

    validate(n);

    return 0;
}
