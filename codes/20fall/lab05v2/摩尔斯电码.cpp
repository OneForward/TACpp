#include <iostream>
using namespace std;

const char* M[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
    "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", 
};

int main()
{
    // freopen("cases/摩尔斯电码.in", "r", stdin);
    const int N = 1000;
    
    char s[N];
    cin.getline(s, N);

    int pos = 0; char ch;
    while (ch = s[pos++]) {
        if (ch == ' ') cout << "   ";
        else if (isalpha(ch)) cout << M[toupper(ch) - 'A'] << " ";
        else cout << M[ch - '0' + 26] << " ";
    }
    
    return 0;
}
