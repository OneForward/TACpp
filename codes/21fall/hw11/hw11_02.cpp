#include <iostream>
#include <string>
using namespace std;
class Building
{
    int layernumber;
    int housenum;
    float sumarea;

public:
    Building();
    Building(int m, int n, float s)
    {
        cout << "base constructor called." << endl;
        layernumber = m;
        housenum = n;
        sumarea = s;
    }
    void print()
    {
        cout << "this is a " << layernumber << "-story building" << endl;
        cout << "there are " << housenum << " houses" << endl;
        cout << "And total area is " << sumarea << endl;
    }
};


//定义House类

struct House: public Building
{
    int bedroomnum, bathroomnum;
    House(int m, int n, int s, int bednum, int bathnum): 
        Building(m, n, s), bedroomnum{bednum}, bathroomnum{bathnum} { cout << "House constructor called.\n"; }
    
    void print() {
        Building::print();
        printf("bedroomnum=%d\nbathroomnum=%d\n", bedroomnum, bathroomnum);
    }
};

//end

//定义Office类
struct Office: public Building
{
    int stuffnum, telnum;
    Office(int m, int n, int s, int stuff, int tel): 
        Building(m, n, s), stuffnum{stuff}, telnum{tel} { cout << "Office Constructor called.\n"; }
    
    void print() {
        Building::print();
        printf("stuffnum=%d\ntelnum=%d\n", stuffnum, telnum);
    }
};

//end

int main()
{
    Building build1(18, 360, 8000);
    build1.print();
    House house(6, 24, 2880, 4, 2);
    house.print();
    Office office(18, 360, 8000, 4, 4);
    office.print();
    return 0;
}
