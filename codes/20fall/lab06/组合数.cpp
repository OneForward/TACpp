#include<iostream>  
using namespace std; 

int combination(int n, int m) {
    if (m > n/2) return combination(n, n-m);
    
    int ans = 1;
    for (int i = n-m+1; i <= n; ++i) { 
        ans *= i;
    } 
    while (m) {
        ans /= m; m--;
    }
    return ans;
}

int main(){
	int n, m; cin >> n >> m;
    
    if (n < m) cout << "wrong!";
    else cout << combination(n, m);
    return 0;
}