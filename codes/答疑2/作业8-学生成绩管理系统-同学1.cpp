#include <iostream>

using namespace std;
struct Student
{
    long long sid;
    char name[51];
    int grades[3];
};
Student student[100];
int k=0;
void insert();
void change();
void deleta();
void search1();
void search2();
void paixu1();
void paixu2();
int main(int argc, char const *argv[])
{   
    freopen("作业8-学生成绩管理-测例1.txt", "r", stdin);

    int n;
    bool b;
    b=true;
    do  {
      cin>>n;
      switch (n)
      {
          case 1:insert();break;
          case 2:change();break;
          case 3:deleta();break;
          case 4:search1();break;
          case 5:search2();break;
          case 6:paixu1();break;
          case 7:paixu2();break;
          case 0:b=false;break;
      }

    }while (b);
    return 0;
}
void insert()
{  long long a;
   int i,n,j;
   cin>>a;
   bool b;
   b=true;
   for (i=0;i<k;i++)
     if (student[i].sid==a) {j=i;b=false;}
   if (b) {j=k;k++;}
   student[j].sid=a;
   for (i=0;i<3;i++)
     cin>>student[j].grades[i];
   cin>>ws;
   cin.getline(student[j].name,51,'\n');
}

void change()
{
   long long a;
   bool b;
   b=false;
   int i,j,j1,j2,j3;
   char c[51];
   cin>>a;
   for (i=0;i<k;i++)
     if (student[i].sid==a) {j=i;b=true;break;}
   cin>>j1>>j2>>j3;
   cin>>ws;
   cin.getline(c,51,'\n');
   if (b) {student[j].grades[0]=j1;
           student[j].grades[1]=j2;
           student[j].grades[2]=j3;
           for (i=0;i<51;i++)
             {student[j].name[i]=c[i];
              if (c[i]=='\0') break;}
   }
}

void deleta()
{   long long a;
    bool b;
    int i,j,s;
    b=false;
    cin>>a;
    for (i=0;i<k;i++)
      if (student[i].sid==a) {b=true;break;}
    if  (b) {for (j=i;j<k-1;j++)
              {
                  student[j].sid=student[j+1].sid;
                  for (s=0;s<3;s++)
                    student[j].grades[s]=student[j+1].grades[s];
                  for (s=0;s<51;s++)
                    student[j].name[s]=student[j+1].name[s];
              }
              k--;}
}
void search1()
{
    long long a;
    cin>>a;
    int i,j;
    bool b;
    b=false;
    for (i=0;i<k;i++)
      if (student[i].sid==a) {j=i;b=true;break;}
    if (b) {cout<<student[j].sid<<" ";
            for(i=0;i<3;i++) cout<<student[j].grades[i]<<" ";
            for(i=0;i<51;i++) {if (student[j].name[i]=='\0') break;
                               cout<<student[j].name[i];}
    cout<<endl;
    }
}
void search2()
{
    char str[51];
    cin >> ws;
    cin.getline(str,51,'\n');
    int i,j;
    bool b;

    for (i=0;i<k;i++)
      {
         b=true;
         j=0;
         while(true)
           {
               if (student[i].name[j] != str[j]) {b=false;break;}
               if (student[i].name[j]=='\0') break;
               j++;
           }

      if (b) {cout<<student[i].sid<<" ";
            for(j=0;j<3;j++) cout<<student[i].grades[j]<<" ";
            for(j=0;j<51;j++) {if (student[i].name[j]=='\0') break;
                               cout<<student[i].name[j];}cout<<endl;}

    }
}
void paixu1()
{

}
void paixu2()
{

}
