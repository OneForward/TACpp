#include <iostream>
#include <algorithm>
using namespace std;

bool isAccaptable(const string& s) {
    if (s.size() > 20) return false;

    static const char ACCAPT[] = ",.\" @#$";
    return all_of(s.begin(), s.end(), [&](char si) {
        if (isalnum(si)) return true;
        for (auto ch: ACCAPT) { 
            if (si == ch) return true;
        }
        return false;
    } );
}

bool isSensitive(char lft, char rht)
{
    return string{lft, rht} == "L4" ||
           string{lft, rht} == "FD";
}

bool isIgnoredString(const string &s)
{
    const static char IGNORED[] = "@#$";
    for (auto si : s)
    {
        if (none_of(IGNORED, IGNORED + 3, [&](char ch) { return ch == si; }))
            return false;
    }
    return true;
}

int main()
{
    string input;
    cin >> input;

    string s = input;
    if (!isAccaptable(s))
    {
        cout << "输入不符合要求";
        return 0;
    }

loop:
{
    s = input;
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = i + 1; j < s.size(); ++j)
        {
            if (isSensitive(toupper(s[i]), toupper(s[j])))
            {
                if (isIgnoredString(s.substr(i + 1, j - i - 1)))
                {
                    input = input.replace(i, j - i + 1, "");
                    goto loop;
                }
            }
            for (int k = i; k < j; ++k)
            {
                if (string{(char)toupper(s[i]), s[k], s[j]} == "D26")
                {
                    if (isIgnoredString(s.substr(i + 1, k - i - 1)) &&
                        isIgnoredString(s.substr(k + 1, j - k - 1)))
                    {
                        input = input.replace(i, j - i + 1, "");
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
