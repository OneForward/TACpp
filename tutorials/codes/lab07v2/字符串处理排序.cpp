#include <iostream>
#include <cstring>
using namespace std;

void bubbleSort(char** A, int n) {    
    for (int i = n-1; i >= 0; --i) {
        bool exist_swap = false;
        for (int j = 0; j < i; ++j) {
            if (strcmp(A[j], A[j+1]) < 0) 
                swap(A[j], A[j+1]), exist_swap = true;
        }
        if (! exist_swap) break;
    }
}


int main()
{
    int n;
    cin >> n; cin >> ws;

    char* lines[35];
    for (int i = 0; i < n; ++i) 
    { 
        lines[i] = new char[80];
        cin.getline(lines[i], 80);
    }

    char ch; cin >> ch;

    for (int i = 0; i < n; ++i) 
    { 
        size_t len = strlen(lines[i]);
        for (size_t j = 0; j < len; ++j) 
            if (lines[i][j] == ch) lines[i][j] = 0;

        size_t pos = 0;
        for (size_t j = 0; j < len; ++j)  
            if (lines[i][j]) lines[i][pos++] = lines[i][j];
        lines[i][pos] = 0;
    }

    bubbleSort(lines, n);

    for (int i = 0; i < n; ++i) 
    {
        cout << lines[i] << endl;
    }

    return 0;
}
