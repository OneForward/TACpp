#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M; 
    
    int f = 0;
    for (int n = 1; n <= N; ++n) f = (f + M) % n;
    cout << f + 1;

    return 0;
}
