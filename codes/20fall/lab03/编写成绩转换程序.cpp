#include<iostream>
using namespace std;

int main() 
{

    int x; cin >> x;
    if (x > 90) cout << "A";
    else if (x > 80) cout << "B";
    else if (x > 70) cout << "C";
    else if (x > 60) cout << "D";
    else cout << "E";

    return 0;
}


