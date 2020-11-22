#include <iostream>

using namespace std;


int main()
{
    int a, b; 
    cin >> a >> b;

    int answers[] = { 0, 1, 153, 370, 371, 407 };
    size_t lft = 0, rht = 0;
    while (lft < 6 && answers[lft] < a) lft++;
    while (rht < 6 && answers[rht] <= b) rht++;

    if (lft == rht) cout << "no";
    while (lft < rht) cout << answers[lft++] << " ";
    return 0;
}
