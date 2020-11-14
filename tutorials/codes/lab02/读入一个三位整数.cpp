#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x; cin >>x;
    printf("%d的百位数字是%d，十位数字是%d，个位数字是%d\n", x, x/100, x/10%10, x%10);
    return 0;
}
