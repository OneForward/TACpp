#include <iostream>
using namespace std;

int main()
{
    
    int N;  cin >> N;
    int x, prev = 0, ans = -1000;

    while (N--) {
        cin >> x;
        prev = max(x, prev + x);
        ans = max(ans, prev);
    }

    cout << ans;

    return 0;
}
