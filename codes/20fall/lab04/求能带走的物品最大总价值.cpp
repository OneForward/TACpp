#include <iostream>

using namespace std;


int main()
{

    int n, W; cin >> n >> W;
    
    int ans = 0;
    for (int i = n-W+1; i <= n; ++i) { 
        ans += i;
    }
    cout << ans;
    return 0;
}
