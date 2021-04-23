#include <iostream>

using namespace std;

struct Test
{
    string a;
    string* b; // 绑定自己的地址

    Test(string s) { a = s, b = &a ; }
};


int main()
{
    Test test1("test1"), test2("test2");

    cout << "test1.a = " << test1.a << ", test1.b = " << *test1.b << endl;
    cout << "test2.a = " << test2.a << ", test2.b = " << *test2.b << endl;

    swap(test1, test2);

    test1.a = "I've totally changed";

    cout << "test1.a = " << test1.a << ", test1.b = " << *test1.b << endl;
    cout << "test2.a = " << test2.a << ", test2.b = " << *test2.b << endl;

    // printf("test1.a = %s, test1.b = %s\n", test1.a.c_str(), test1.b->c_str());
    // printf("test2.a = %s, test2.b = %s\n", test2.a.c_str(), test2.b->c_str());
    

    return 0;
}


