#include <iostream>
#include <cstring>
using namespace std;

const char* MONTH[] = {
    "Jan", "Feb", "Mar", "Apr", 
    "May", "June", "July", "Aug",
    "Sept", "Oct", "Nov", "Dec",
};

//请在此处定义getDate函数，main函数内容不要更改
void getDate(int& day, int& month, int& year) {
    char s[100];
    cin.getline(s, sizeof(s), '-');
    day = atoi(s);
    
    cin.getline(s, sizeof(s), '-');
    for (int i = 0; i < 12; ++i) { 
        if (strcmp(s, MONTH[i]) == 0) month = i + 1;
    }
    
    cin.getline(s, sizeof(s));
    year = atoi(s);
}

int main()
{
    int day, month, year;
    getDate(day,month,year);
    cout<<" "<<day<<" "<<month<<" "<<year<<endl;
    return 0;
}
