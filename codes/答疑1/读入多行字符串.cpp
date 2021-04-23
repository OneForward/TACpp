#include <iostream>
using namespace std;

int main()
{
    freopen("cases/multiline.txt", "r", stdin);

    // 错误写法
    int n; 
    char lines[10][80] { }; // 保存不超过10个字符串,每个字符串长度不超过80
    cin >> n;  cin >> ws; // skip whitespace
    for (int i=0; i < n; ++i) cin.getline(lines[i], 80);


    // 正确写法
    // int n; 
    // char lines[10][80]; // 保存不超过10个字符串,每个字符串长度不超过80
    // cin >> n; cin >> ws; // 添加一个跳过空白的语句
    // for (int i=0; i < n; ++i) cin.getline(lines[i], 80);
    return 0;
}