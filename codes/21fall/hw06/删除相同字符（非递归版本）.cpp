#include <iostream>
#include <cstring>
using namespace std;

void deletechar(char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    for (int i = 0; i < len1; ++i)
        for (int j = 0; j < len2; ++j)
            if (str1[i] == str2[j]) str1[i] = 0;

    size_t pos = 0;
    for (int i = 0; i < len1; ++i)
        if (str1[i]) str1[pos++] = str1[i];
    str1[pos] = 0;
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