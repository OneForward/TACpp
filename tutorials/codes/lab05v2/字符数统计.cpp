#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("cases/字符数统计.in", "r", stdin);

    int n; cin >> n; cin >> ws;

    int letters = 0, digits = 0, others = 0;
    while (n--) { 
        char s[80]{}; 
        cin.getline(s, 80);
        size_t pos = 0; char ch;
        while (s[pos]) {
            ch = s[pos]; pos++;
            if (isalpha(ch)) letters++;
            else if (isdigit(ch)) digits++;
            else if (!isspace(ch)) others++;
        }
    }
    printf("英文字母：%d\n", letters);
    printf("数字：%d\n", digits);
    printf("其他字符：%d\n", others);
    return 0;
}
