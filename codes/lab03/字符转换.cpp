#include<iostream>
using namespace std;

int main() 
{
    char ch; 
    cin >> ch;
    if ('a' <= ch && ch <= 'z') ch = ch - ('a' - 'A');
    else if ('A' <= ch && ch <= 'Z') ch = ch + ('a' - 'A');
    cout << ch;
    return 0;
}


