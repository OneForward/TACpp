#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    int c = 0;
    double nx, ny;
    Point p, q;
    
    while(c != -1){
        cin >> c;
        switch (c){
            case 0:
                cout << p.x << " " << p.y << endl;
                break;
            case 1:
                cout << q.x << " " << q.y << endl;
                break;
            case 2:
                cin >> nx;
                p.SetX(nx);
                break;
            case 3:
                cin >> ny;
                p.SetY(ny);
                break;
            case 4:
                cin >> nx >> ny;
                p.SetPoint(nx, ny);
                break;
            case 5:
                q.SetPoint(p);
                break;
            case 6:
                cin >> nx;
                q.SetX(nx);
                break;
            case 7:
                cin >> ny;
                q.SetY(ny);
                break;
            case 8:
                cin >> nx >> ny;
                q.SetPoint(nx, ny);
                break;
            case 9:
                p.SetPoint(q);
                break;
            default:
                break;
        }
    }
    
    return 0;
}