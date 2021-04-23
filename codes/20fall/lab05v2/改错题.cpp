// 请在下方修改代码
/********** Begin *********/
#include <iostream>
using namespace std;

int main(){
    // freopen("cases/改错题.in", "r", stdin);
    int i, j, n = 0;
    char str[80];

    i = 0;
    while((str[i]=cin.get()) != -1 && str[i] != '\n')
        i++;
    str[i] = '\0';

    for(j = 0; str[j]!=0; j++){
        if(str[j]>='0' && str[j]<='9')
            n = n*10 +str[j] - '0';
    }
    cout << n << endl;
    return 0;
}
/********** End *********/