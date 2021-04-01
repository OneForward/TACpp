#include <iostream>

using namespace std;

int lastRemaining(int N, int M) {
    if (N == 1) return 0;
    return (lastRemaining(N-1, M) + M) % N;
}

int main()
{
    int N, M;
    cin >> N >> M; 
    
    cout << lastRemaining(N, M) + 1;
    return 0;
}
