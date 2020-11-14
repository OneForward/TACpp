#include <iostream>
#include <cstring>
using namespace std;

void bubbleSort(char* A, int n) {    
    for (int i=n-1; i>=0; --i) {
        bool exist_swap = false;
        for (int j=0; j<i; ++j) {
            if (A[j] < A[j+1]) swap(A[j], A[j+1]), exist_swap = true;
        }
        if (! exist_swap) break;
    }
}

int main(int argc, char const *argv[])
{
    // freopen("cases/字符重排序.in", "r", stdin);

    char s[100];
    cin.getline(s, sizeof(s));

    bool Cs[127]{};

    size_t pos = 0;
    while (s[pos]) {
        Cs[s[pos]] = true; pos++;
    }

    pos = 0;
    for (char i = 127; i >= 0; --i) { 
        if (Cs[i]) s[pos++] = i;
    }
    s[pos] = 0;

    cout << s;
    return 0;
}
