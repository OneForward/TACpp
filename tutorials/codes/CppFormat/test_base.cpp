#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 15;

    printf( "十六进制：%x\n", num);
    printf( "八进制：%o\n", num);
    printf( "十进制：%d\n", num);
    
    printf("\n");


    cout << "十六进制：" << hex << num << endl
         << "八进制：" << oct << num << endl
         << "十进制：" << dec << num << endl << endl;

    cout << "十六进制：" << setbase(16) << num << endl
         << "八进制：" << setbase(8) << num << endl
         << "十进制：" << setbase(10) << num << endl << endl;


    return 0;
}
