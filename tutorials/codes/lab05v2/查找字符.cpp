#include <iostream>
using namespace std;

int main()
{
    // freopen("cases/查找字符.in", "r", stdin);

    char s[100];
    cin.getline(s, sizeof(s));
    char key; cin.get(key);

    int pos = 0, ans = -1;
    while (s[pos])
    {
        if (s[pos] == key)  ans = pos;
        pos++;
    }
    if (ans >= 0) printf("Index=%d\n", ans);
    else printf("Not Found");
    return 0;
}
