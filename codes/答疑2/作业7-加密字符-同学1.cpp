#include <iostream>
using namespace std;

int main()
{
    // https://www.educoder.net/tasks/9rv7mgqejyb2
    freopen("cases/作业7-加密字符-同学1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /*Start your code here*/
    char *pnt;
    pnt = new char[30]{};
    cin.get(pnt,30);


    int flag = 1;
    int stop=1;

    for(int i=0; pnt[i]!='\0'; i++)
    {
        if (flag == 8)
        flag = 1;

        switch(flag)
        {
            case 1: pnt[i]+=8; break;
            case 2: pnt[i]+=7; break;
            case 3: pnt[i]+=3; break;
            case 4: pnt[i]+=4; break;
            case 5: pnt[i]+=9; break;
            case 6: pnt[i]+=6; break;
            case 7: pnt[i]+=2; break;
        }
        flag++;

        if (int(pnt[i])>122)
        pnt[i]-=91;
        stop++;
    }

    for (int i=0; i<stop; i++)
        cout << pnt[i];

    cout << endl;

    //以下为解密部分

    int qizi = 1;
    int tingxia=1;

    for(int i=0; pnt[i]!='\0'; i++)
    {
        if (qizi == 8)
        qizi = 1;

        switch(qizi)
        {
            case 1: pnt[i]-=8; break;
            case 2: pnt[i]-=7; break;
            case 3: pnt[i]-=3; break;
            case 4: pnt[i]-=4; break;
            case 5: pnt[i]-=9; break;
            case 6: pnt[i]-=6; break;
            case 7: pnt[i]-=2; break;
        }
        qizi++;

        if (int(pnt[i])<32)
        pnt[i] = 122-(32-pnt[i]-1);
        tingxia++;
    }

    for (int i=0; i<tingxia; i++)
    if (pnt[i]) cout << char(pnt[i]);

    delete []pnt;

    /*end your code*/
    return 0;
}
