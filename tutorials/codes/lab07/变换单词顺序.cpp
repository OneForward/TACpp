#include <iostream>
using namespace std;

int main()
{
    char line[105];
    cin.getline(line, sizeof(line));

    char* words[15]; size_t wi = 0;
    words[wi++] = line;

    // 将字符串中的 空格 替换为终止符 \0, 
    // 然后将每个单词首字符的地址存入指针数组 word 中
    size_t p = 0; 
    while (line[p]) {
        if (line[p] == ' ') line[p] = 0, words[wi++] = &line[p+1];
        p++; 
    }
    cout << wi << endl;

    char ch;
    while (cin.get(ch)) {
        cout << words[ch-'0'] << " ";
    }

    return 0;
}
