#include <iostream>
#include <string>
using namespace std;
//完成嵌套类型的定义
struct date
{
    int year;
    int month;
    int day;
};
struct people
{
    char name[20];
    date birthday;
    char telephone[20];
    char locate[50];
};
//两个函数，输入和输出
void set(people &p);
void show(people &p);
int main(int argc, char const *argv[])
{
    freopen("作业8-通讯录结构体-测例1.txt", "r", stdin);

    int n;
    cin>>n;
    people *p;
    p=new people[n];
    int i;
    for(i=0;i<n;++i)
    {
        set(p[i]);
    }
    //for(i=0;i<n;++i)  {show(p[i]);}
    int *age;
    age=new int[n];
    for(i=0;i<n;++i)
    {
        age[i]=(p[i].birthday.year)*365+p[i].birthday.month*30+p[i].birthday.day;
    }

    //for(i=0;i<n;++i) {cout<<age[i];}
    //现在已经读入了数据并且读入了年龄大小，接下来通过冒泡排序，将年龄从小到大排序（数字从大到小）
    //age数组存了年龄，order数组存了顺序
    //在对age数组排序的同时连带order数组即可
    int *order;
    order=new int[n];
    //记录顺序
    for(i=0;i<n;++i) {order[i]=i+1;}
    //排序
    bool flag;
    int j,k,tmp1,tmp2;
    //双重排序
    for(j=1;j<n;++j)
    {
        flag=false;
        for(k=0;k<n-j;++k)
        {
            if(age[k+1]>age[k])
             {tmp1=order[k];order[k]=order[k+1];order[k+1]=tmp1;
              tmp2=age[k];age[k]=age[k+1];age[k+1]=tmp2;flag=true;}
            if(!flag) break;
        }
    }

    //for(i=0;i<n;++i) cout<<order[i];
    //order顺序准确
    int num;
   // for(i=0;i<n;++i) {show(p[i]);}
    for(i=0;i<n;++i)
    {
        num=order[i];
        show(p[num-1]);
        //cout<<endl;
    }

    delete p;
    delete age;
    delete order;
    return 0;
}
void set(people &p)
{
    cin.getline(p.name,20,' ');
    cin>>p.birthday.year>>p.birthday.month>>p.birthday.day; //cin >> ws;
    cin.getline(p.telephone,20,' '); //cin >> ws;
    cin.getline(p.locate,50,'\n'); //cin >> ws;
}
void show(people &p)
{
    cout<<p.name<<" "<<p.birthday.year<<" "<<p.birthday.month<<" "
    <<p.birthday.day << " "<<p.telephone<<" "<<p.locate<<endl;
}