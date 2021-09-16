#include <iostream>
#include <cstring>
using namespace std;

const char ACCAPT[] = ",.\" @#$";
const char IGNORED[] = "@#$";

bool isAccaptable(char ch) {
    if (isalnum(ch)) return true;

    const char* p = ACCAPT;
    while (*p) { 
        if (ch == *p) return true;
        p++;
    }
    return false;
}

bool isAccaptableString(const char* s, int len) {
    if (len > 20) return false;

    while (len--) {
        if (!isAccaptable(*s)) return false;
        s++;
    }
    return true;
}

bool isIgnored(char ch) {
    const char* p = IGNORED;
    while (*p) { 
        if (ch == *p) return true;
        p++;
    }
    return false;
}

bool isIgnoredString(const char* s, int len)
{
    while (len--) {
        if (!isIgnored(*s)) return false;
        s++;
    }
    return true;
}

bool isSensitive(char lft, char rht)
{
    return (lft == 'L' && rht == '4') || (lft == 'F' && rht == 'D');
}

void erase(char* s, int pos, int cnt) {
    int rht = pos + cnt;
    while (s[rht]) {
        s[pos++] = s[rht++];
    }
    s[pos] = 0;
}

int main()
{
    char input[1005];
    cin >> input;
    
    int len = strlen(input);
    
    if (!isAccaptableString(input, len)) {
        cout << "输入不符合要求";
        return 0;
    }

loop:
{
    char* s = input; len = strlen(s);
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (isSensitive(toupper(s[i]), toupper(s[j])))
            {
                if (isIgnoredString(s + i + 1, j - i - 1))
                {
                    erase(input, i, j - i + 1);
                    goto loop;
                }
            }
            for (int k = i; k < j; ++k)
            {
                if (toupper(s[i]) == 'D' && s[k] == '2' && s[j] == '6')
                {
                    if (isIgnoredString(s + i + 1, k - i - 1) &&
                        isIgnoredString(s + k + 1, j - k - 1))
                    {
                        erase(input, i, j - i + 1);
                        goto loop;
                    }
                }
            }
        }
    }
}

    cout << input;

    return 0;
}
