#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // freopen("cases/寻找字符串.in", "r", stdin);

    const int N = 200;
    char s1[N], s2[N];
    cin.getline(s1, N);
    cin.getline(s2, N);

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    if (len1 < len2 || len2 == 0) { cout << -1; return 0; }

    for (size_t start = 0; start <= len1-len2; ++start) { 
        size_t p2 = 0;
        for (p2 = 0; p2 < len2; ++p2) { 
            if (s2[p2] != s1[start+p2]) break;
        }
        if (p2 == len2) { cout << start; return 0; }
    }
    
    cout << -1;
}
