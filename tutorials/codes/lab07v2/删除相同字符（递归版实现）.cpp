#include <iostream>
#include <cstring>
using namespace std;

void deletechar(char *str1, const char *str2)
{
    if (*str2 == 0) return;

    size_t len = strlen(str1);
    for (int i = 0; i < len; ++i)
        if (str1[i] == *str2) str1[i] = 0;

    size_t pos = 0;
    for (int i = 0; i < len; ++i)
        if (str1[i]) str1[pos++] = str1[i];
    str1[pos] = 0;

    deletechar(str1, str2 + 1);
}

int main()
{
    char str1[80] = {'\0'};
    char str2[80] = {'\0'};
    cin.getline(str1, 80);
    cin.getline(str2, 80);
    deletechar(str1, str2);

    cout << str1 << endl;
    return 0;
}