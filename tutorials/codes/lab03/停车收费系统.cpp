#include<iostream>
using namespace std;

int main() 
{
    char type; int t1, t2, fee; 
    cin >> type >> t1 >> t2;
    
    int dt = t2 - t1;
    switch (type)
    {
    case 'c':
        fee = dt > 3 ? 10 * (dt-3) + 15 : 5 * dt;
        break;
    
    case 'b':
        fee = dt > 2 ? 15 * (dt-2) + 20 : 10 * dt;
        break;
    
    default:
        fee = dt > 1 ? 15 * (dt-1) + 10 : 10 * dt;
        break;
    }

    cout << fee;
    return 0;
}


