#include <iostream>
#include <cstring>

using namespace std;


char* f( ) {
    char* s = new char[10];  // 开辟了内存空间
    strcpy(s, "hello"); // ok
    return s;
}

void g( char* s) {
    cout << s << endl;
    delete s; // g 回收了这片内存空间
}


int main()
{
    char* s = f(); // 内存空间的访问权限从 f 内部移交给  main 内部
    cout << s << endl;

    g(s); // 将访问权限分享给 g

    cout << s << endl; // 错误 这片空间已经被回收了，main 不能再访问这片空间
    delete s; // 错误， main 不能再访问这片空间，也无法再次 delete

    return 0;
}
