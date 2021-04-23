#include<iostream>
using namespace std;

int main() 
{
    float water; cin >> water;
    float fee = 0;

    if (water > 10) fee = (water-10) * 2 + 15;
    else fee = water * 1.5;

    cout << fee;
    return 0;
}


