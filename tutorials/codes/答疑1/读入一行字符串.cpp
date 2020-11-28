#include <iostream>
using namespace std;

int main()
{
    // freopen("cases/single.txt", "r", stdin);

    // const char target[] = "AEIOUaeiou";

    char s[] = "hello world!";
    char* p = s;

    p[5] = 0;
    cout << p+3;

    // 错误写法1
    // int i = 0; char s[80] { };
    // while (cin >> s[i]) i++; // 无法获得空白字符


    // 错误写法2
    // char ch; 
    // int i = 0; char s[80] {};
    // while ( !cin.eof() && (ch = cin.get() ) != '\n' ) s[i++] = ch; // 可能错误读入换行符，错误读入 EOF=-1
    

    // 错误写法3
    // int i = 0; char s[80]{};
    // while ( (s[i] = cin.get()) != EOF ) i++; // 假如没有换行符，将会错误读入 EOF=-1
        
    // 正确写法1
    // char s[80]; char str2[80];
    // cin.getline(s, 80, ' ');
    // cin.getline(str2, 80, ' ');


    // 正确写法2
    // int i = 0; char s[80];
    // while ( cin.get(s[i]) && s[i] != '\n' ) ++i; // 小的潜在错误, 缺少80字符判断
    return 0;
}