#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    double num = 4.0; 
    printf( "宽度为10，右对齐：[%10g]\n"
            "宽度为10，左对齐：[%-10g]\n"
            "宽度为10，右对齐，空白补0：[%010.g]\n"
            "\n", num, num, num);


    cout << "宽度为10，右对齐：[" 
         << setw(10) << num << "]" << endl
         
         << "宽度为10，左对齐：[" << left
         << setw(10) << num << "]" << endl
         << resetiosflags(ios::left)
         
         << "宽度为10，右对齐，空白补0：[" << right
         << setfill('0') << setw(10) << num << "]" << endl
         << resetiosflags(ios::right)
                                     
         << "宽度为10，左对齐，空白补*：[" << left
         << setfill('*') << setw(10) << num << "]" << endl
         << resetiosflags(ios::left);

    
    auto s = "Hello";
    
    printf("\n");
    printf("宽度为10，右对齐: [%10s] \n", "Hello");
    printf("宽度为10，左对齐: [%-10s] \n", "Hello");   
    printf("\n");


    cout << "宽度为10，右对齐：[" << setfill(' ')
         << setw(10) << s << "]" << endl
         
         << "宽度为10，左对齐：[" << left
         << setw(10) << s << "]" << endl
         << resetiosflags(ios::left);


    double x = 20.0 / 3;

    printf("\n");
    printf("保留3位小数: %.3f\n", x);
    printf("保留3位小数，宽度10且左对齐: [%-10.3f] [%-10.3f]\n", x, 2.);
    printf("\n");


    cout << "保留3位小数: " 
         << fixed << setprecision(3) << x << endl 
         << "保留3位小数，宽度10且左对齐: [" << left
         << setw(10) << setfill(' ') << x << "] ["
         << setw(10) << setfill('*') << x << "]\n" 
         << resetiosflags(ios::left);


    return 0;
}
