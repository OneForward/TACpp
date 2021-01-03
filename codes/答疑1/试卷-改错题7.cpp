#include <iostream>
using namespace std;

int main()
{
    char s[] = "abcde";
    int a[] = {1, 2, 3, 4 ,5, 6};
    cout << "len(s) = " << sizeof(s)-1 << endl;
    cout << "len(a) = " << sizeof(a) / sizeof(int) << endl;
    return 0;
}
 