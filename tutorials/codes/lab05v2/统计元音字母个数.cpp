#include <iostream>
using namespace std;

int main()
{
    // freopen("cases/统计元音字母个数.in", "r", stdin);

    char s[100];
    cin.getline(s, sizeof(s));
    
    const char target[] = "AEIOUaeiou";

    size_t pos = 0, cnt = 0;
    while (s[pos])
    {
        for (size_t i = 0; i < sizeof(target); ++i) { 
            if (target[i] == s[pos]) cnt++;
        }
        pos++;
    }
    
    printf("Count=%d\n", cnt);
    return 0;
}
