#include "class.h"

double Cel2Fahren(double celsius) { return 32 + celsius * 1.8; }
double Fahren2Cel(double fahren) { return (fahren - 32) / 1.8; }

// constructor (default Celsius)
Thermometer::Thermometer(){};
Thermometer::Thermometer(double temp)
{
    tempCelsius = temp;
    tempFahrenheit = Cel2Fahren(temp);
};
Thermometer::~Thermometer(){};

// set temperature
void Thermometer::SetTempCelsius(double tempCelsius)
{
    tempCelsius = tempCelsius;
    tempFahrenheit = Cel2Fahren(tempCelsius);
};
void Thermometer::SetTempFahrenheit(double tempFahrenheit)
{
    tempFahrenheit = tempFahrenheit;
    tempCelsius = Fahren2Cel(tempFahrenheit);
};

// display temperature
double Thermometer::GetTempCelsius() { return tempCelsius; };
double Thermometer::GetTempFahrenheit() { return tempFahrenheit; };