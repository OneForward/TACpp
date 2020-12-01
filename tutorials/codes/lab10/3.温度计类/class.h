#ifndef CLASS_H
#define CLASS_H

class Thermometer
{
private:
    double tempCelsius;
    double tempFahrenheit;
public:
    // constructor (default Celsius)
    Thermometer();
    Thermometer(double temp);
    ~Thermometer();

    // set temperature
    void SetTempCelsius(double tempCelsius);
    void SetTempFahrenheit(double tempFahrenheit);

    // display temperature
    double GetTempCelsius();
    double GetTempFahrenheit();
};



#endif /* CLASS_H */