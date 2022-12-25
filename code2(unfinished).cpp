#include<bits/stdc++.h>
using namespace std;

int arr[10][10],q[1001];
int m,n;

void create(){
    int cnt=0;
    srand((int)time(NULL));
    m=rand()%6+2;
    n=rand()%6+2;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=rand()%10;
            q[cnt++]=a[i][j];
        }
    }
    return ;
}

void myprint(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<setw(5);
        }
        cout<<endl;
    }
}

void move(){
    int order=0,
}

int main(){
    create();
    cout<<m<<" "<<n<<endl;
    cout<<"原矩阵为："<<endl;
    myprint();
    cout<<endl;
    cout<<"现矩阵为："<<endl;
    move();
    myprint();
    return 0;
}
