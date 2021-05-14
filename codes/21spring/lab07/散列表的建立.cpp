#include <iostream>
using namespace std;
int main()
{
    int P, M, N, x;
    cin >> P >> M >> N;

    int* HashTable = new int[M];
    for (int i=0; i<M; ++i) HashTable[i] = -1;

    int* ProbeCounter = new int[M]{};
    for (int i=0; i<N; ++i)  {
        cin >> x;
        int pos = x % P, cnt = 1;
        while (HashTable[pos] != -1) pos = (pos+1) % M, cnt++;
        HashTable[pos] = x; ProbeCounter[pos] = cnt;
    }
    
    for (int i=0; i<M; ++i) cout << i << " "; cout << endl;
    for (int i=0; i<M; ++i) cout << HashTable[i] << " "; cout << endl;
    for (int i=0; i<M; ++i) cout << ProbeCounter[i] << " "; cout << endl;
    return 0;
}