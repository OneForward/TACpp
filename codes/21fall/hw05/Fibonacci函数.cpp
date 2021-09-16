#include<iostream>
using namespace std;

int fib() {
    static int x = 0, y = 1;
    swap(x, y); x += y;
    return x;
}

int main()
{
    int i;
    for(i = 0; i < 10; i++)
        cout << fib() << endl;
	return 0;
}
