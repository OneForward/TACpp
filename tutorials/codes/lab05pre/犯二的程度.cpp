#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char s[105];
    cin.getline(s, sizeof(s));

    int len = 0,  twos = 0;
    while (s[len]) { 
        if (s[len] == '2') twos++;
        len++;
    }

    float scale = 1;
    if ((s[len-1] - '0') % 2 == 0) scale *= 2;
    if (s[0] == '-') scale *= 1.5, len--;

    cout << scale * twos / len ;

    return 0;
}
