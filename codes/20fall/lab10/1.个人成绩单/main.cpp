#include <iostream>
#include "class.h"
#include <cstring>

using namespace std;

int main()
{
    PersonScore p;
    int c = 0;
    int m, e, cs;

    while(c != -1){
        cin >> c;
        switch (c){
            case 0:
                cin >> m >> e >> cs;
                p.GiveValue(m, e, cs);
                break;
            case 1:
                p.Display();
                break;
            case 2:
                cout << p.GetHigh() << endl;
                break;
            case 3:
                cout << p.GetLow() << endl;
                break;
            case 4:
                if(p.isMathPass())
                    cout << "yes" << endl;
                else
                    cout << "no" << endl;
                break;
            case 5:
                if(p.isEnglishPass())
                    cout << "yes" << endl;
                else
                    cout << "no" << endl;
                break;
            case 6:
                if(p.isCSPass())
                    cout << "yes" << endl;
                else
                    cout << "no" << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
