#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    // freopen("cases/字符重排序.in", "r", stdin);

    char s[100];
    cin.getline(s, sizeof(s));

    bool Cs[127]{};

    size_t pos = 0;
    while (s[pos]) {
        Cs[s[pos]] = true; pos++;
    }

    pos = 0;
    for (char i = 127; i >= 0; --i) { 
        if (Cs[i]) s[pos++] = i;
    }
    s[pos] = 0;

    cout << s;
    return 0;
}
