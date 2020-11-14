// 请在下方添加代码
/********** Begin *********/
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
int main(){
    int i, j, m, n;
    int mat[MAX_SIZE+1][MAX_SIZE];

    // cout<<"Please input m, n:";
    cin>>m>>n;
    // cout<<"Input array:\n";
    for(i = 0; i<m; i++){
        for(j = 0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    int tmp[MAX_SIZE];
    for (int j = 0; j < n; ++j) { 
        tmp[j] = mat[0][j];
    }


    for(i = m-1; i>0; i--){
        for(j = 0; j<n; j++){
            mat[(i+1)%m][j]=mat[i][j];
        }
    }

    for (int j = 0; j < n; ++j) { 
        mat[1][j] = tmp[j] ;
    }  

    // cout<<"New array:\n";
    for(i = 0; i<m; i++){
        for(j = 0; j<n; j++){
            cout<<mat[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
/********** End **********/

