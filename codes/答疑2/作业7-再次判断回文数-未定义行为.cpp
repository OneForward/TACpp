#include <iostream>
#include <cstring>
using namespace std;

bool func(char array[], int len);

int main()
{
    freopen("cases/作业7-再次判断回文数.txt", "r", stdin);

    char ch[20];
    bool result;

    cin >> ch;

    //此处填补几行代码
    int i = 0;
    while (ch[i] != '\0')
        i++;
    result = func(ch, i + 1);
    if (result == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

bool func(char array[], int len)
{
    //此处填补几行代码
    while ((len - 2) >= 0)
    {
        // 以下这句语句是 undefined behavior
        if ((*(array++)) != (*(array + (len -= 2))))
            return false;
        // array++; // ok
    }
    return true;
}