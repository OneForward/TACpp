#include <iostream>

using namespace std;

int Magic(int x)
{
    /***********begin************/
    for (int a = 0; a < 9; ++a) { 
        for (int b = 0; b < 9; ++b) { 
            for (int c = 0; c < 9; ++c) { 
                if (x == 122 * a + 212 * b + 221 * c) return 100 * a + 10 * b + c;
            }
        }
    }
    return -1;
    /***********end**************/
}

int main()
{
    int t, m;
    cin >> t;
    while (t--)
    {
        cin >> m;
        int res = Magic(m);
        if (res == -1)
        {
            cout << "The sum you calculated is wrong!\n";
        }
        else
        {
            cout << "The number is " << res << endl;
        }
    }
}
