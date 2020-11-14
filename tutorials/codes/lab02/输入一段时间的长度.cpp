#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x; cin >> x; 
    printf("%d秒为%d小时%d分%d秒\n", x, x/3600, x/60%60, x%60);
    return 0;
}
