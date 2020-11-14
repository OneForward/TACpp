#include <iostream>
#include <cstring>
using namespace std;

bool ispalindrome(char* s, int lft, int rht) {
    while (lft < rht) {
        if (s[lft] != s[rht]) return false;
        lft++; rht--;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    freopen("cases/查找回文字符串.in", "r", stdin);

    const int N = 10005;
    char s[N] {}; size_t len = 0; 
    while ((s[len++] = cin.get()) != -1);

    char s_clean[N];
    int index[N];

    size_t len2 = 0; 
    for (int p1 = 0; p1 < len; ++p1) {
        char ch = s[p1];
        if (isalpha(ch)) {
            s_clean[len2] = tolower(ch);
            index[len2] = p1;
            len2++;
        }
    }

    // O(N^3) 
    int ans = 0, plft, prht;
    for (int i = len2-1; i >= 0; --i) { 
        for (int j = i+ans; j < len2; ++j) { 
            if (ispalindrome(s_clean, i, j)) plft = i, prht = j, ans = j - i;
        }
    }

    cout << ans + 1 << endl;
    
    s[index[prht]+1] = 0;
    cout << (s + index[plft]);

    return 0;
}
