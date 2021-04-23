#include <iostream>
using namespace std;

int main()
{
    char str1[20];
    char str2[20];

    cin.getline(str1,20);
    cin.getline(str2,20);

    char* p1 = str1, *p2 = str2;
    while (*p1 && *p2)  {
        swap(*p1, *p2); 
        p1++; p2++;
    }
    cout << str1 << endl << str2;
    return 0;
}
