#include <iostream>
#include <iomanip>
#include "class.h"

using namespace std;

int main()
{
    int T;
    double temp;
    cin >> T;
    cin >>temp;
    Thermometer thermometer(temp);
    for (int i = 0; i < T; i++) {
        char tmp;
        cin >> tmp;
        switch (tmp) {
        case 'a':
            cin >> temp;
            thermometer.SetTempCelsius(temp);
            break;
        case 'b':
            cin >> temp;
            thermometer.SetTempFahrenheit(temp);
            break;
        case 'c':
            temp = thermometer.GetTempCelsius();
            cout << fixed << setprecision(2) << temp << endl; 
            break;
        case 'd':
            temp = thermometer.GetTempFahrenheit(); 
            cout << fixed << setprecision(2) << temp << endl; 
            break;
        }
    }
    return 0;
}