#include <iostream>
#include <string>
using namespace std;
class BirthDate
{
public:
    BirthDate(int, int, int);
    void display();
    void setbirthday(int, int, int);

private:
    int year;
    int month;
    int day;
};
class Teacher
{
public:
    Teacher(int, string, char);
    void display();

private:
    int num;
    string name;
    char sex;
};
BirthDate::BirthDate(int y, int m, int d) : year(y), month(m), day(d) {}
void BirthDate::setbirthday(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
void BirthDate::display()
{
    cout << "birthday:" << year << '/' << month << '/' << day << endl;
}
Teacher::Teacher(int n, string nam, char s) : num(n), name(nam), sex(s) {}
void Teacher::display()
{
    cout << "num:" << num << endl
         << "name:" << name << endl
         << "sex:" << sex << endl;
}

//begin定义professor类

struct Professor: public BirthDate, public Teacher
{
    Professor(int _num, string _name, int _sex, BirthDate _birth): 
        Teacher(_num, _name, _sex), BirthDate(_birth) {  }
    void display() {
        Teacher::display();
        BirthDate::display();
    }
};

//end

int main()
{
    int num;
    string name;
    char sex;
    int year, month, day;
    cin >> num >> name >> sex;
    cin >> year >> month >> day;
    Professor prof(num, name, sex, BirthDate(year, month, day));
    cin >> year >> month >> day;
    prof.setbirthday(year, month, day);
    prof.display();
    return 0;
}