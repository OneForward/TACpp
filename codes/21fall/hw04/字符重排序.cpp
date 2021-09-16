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

int main()
{
    // freopen("cases/字符重排序.in", "r", stdin);

    char s[100];
    cin.getline(s, sizeof(s));

    size_t len = strlen(s);
    bubbleSort(s, len);

    char s2[100]; s2[0] = s[0];
    size_t p2 = 0;
    for (size_t i = 1; i <= len; ++i) { 
        if (s[i] != s[i-1]) s2[++p2] = s[i];
    }

    cout << s2;
    return 0;
}
