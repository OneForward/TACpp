#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<char, string> M = {
    { 'A', ".-" },
    { 'B', "-..." },
    { 'C', "-.-." },
    { 'D', "-.." },
    { 'E', "." },
    { 'F', "..-." },
    { 'G', "--." },
    { 'H', "...." },
    { 'I', ".." },
    { 'J', ".---" },
    { 'K', "-.-" },
    { 'L', ".-.." },
    { 'M', "--" },
    { 'N', "-." },
    { 'O', "---" },
    { 'P', ".--." },
    { 'Q', "--.-" },
    { 'R', ".-." },
    { 'S', "..." },
    { 'T', "-" },
    { 'U', "..-" },
    { 'V', "...-" },
    { 'W', ".--" },
    { 'X', "-..-" },
    { 'Y', "-.--" },
    { 'Z', "--.." },
    { '0', "-----" },
    { '1', ".----" },
    { '2', "..---" },
    { '3', "...--" },
    { '4', "....-" },
    { '5', "....." },
    { '6', "-...." },
    { '7', "--..." },
    { '8', "---.." },
    { '9', "----." },
};

int main(int argc, char const *argv[])
{
    // freopen("cases/摩尔斯电码.in", "r", stdin);

    const int N = 1000;
    char s[N];
    cin.getline(s, N);

    int pos = 0;
    while (s[pos]) {
        if (s[pos] == ' ') cout << "   ";
        else cout << M[toupper(s[pos])] << " ";
        pos++;
    }
    

    return 0;
}
