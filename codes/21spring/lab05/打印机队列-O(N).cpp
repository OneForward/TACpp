#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    
    int f[202]{};
    int T, N, J;


    cin >> T;
    while (T--) {
        // Time O(N), Space O(N) Extra for each case

        cin >> N >> J;
        
        int time = 1;
        vector<int> P[10];
        for (int i = 0; i < N; ++i)  cin >> f[i]; 

        // 一定会打印的部分
        for (int i = 0; i < N; ++i) {
            if (f[i] > f[J]) {
                time++;
                P[f[i]].push_back(i);
            }
        }

        int prev[11]{}; // 相邻的优先级
        for (int i = 0; i <= 9; ++i) prev[i+1] = P[i].empty() ? prev[i] : i;

        int p = prev[10], idx = N;
        while (p > f[J]) {
            int pos = P[p].back();
            for (auto&& x: P[p]) if (x < idx) pos = x; ; // at most N times
            idx = pos; p = prev[p];
        }
        
        idx %= N;
        while (idx != J) { // at most N times
            if (f[idx] == f[J]) time++;
            idx = (idx + 1) % N;
        }
        cout << time << endl;    
    }

    return 0;
}