#include <iostream>
#include <string>
using namespace std;

int main()
{
    // freopen("cases/寻找字符串.in", "r", stdin);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    auto n = s1.find(s2);
    if (n == string::npos) cout << -1;
    else cout << n;
    return 0;
}
