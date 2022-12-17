#include<bits/stdc++.h>
using namespace std;

int arr[15][15],m,n;
int a[15][15],c[10010],num;
bool flag[15][15];


void before(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

void after(){
    int i=0,j=0,dirx=1,diry=0;
    int total=m*n;
    while(num<total){
        c[num++]=a[i][j];
        flag[i][j]=1;
        i+=dirx,j+=diry;
        if(i>m-1||flag[i][j]){
            i-=dirx,j-=diry;
            dirx=-1,diry=0;
            i+=dirx,j+=diry;
        }
        else if(j>n-1||flag[i][j]){
            i-=dirx,j-=diry;
            dirx=0,diry=1;
            i+=dirx,j+=diry;
        }
        else if(i<0||flag[i][j]){
            i-=dirx,j-=diry;
            dirx=0,diry=-1;
            i+=dirx,j+=diry;
        }
        else if(j<0||flag[i][j]){
            i-=dirx,j-=diry;
            dirx=1,diry=0;
            i+=dirx,j+=diry;
        }
    }
    int t=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]=c[t];
            t++;
            if(t==num) t=0;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    srand((unsigned)time(NULL));
    m=rand()%5+3;
    n=rand()%5+3;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=rand()%10;
        }
    }
    cout<<m<<n<<endl;
    cout<<"before:"<<endl;
    before();
    cout<<"after:"<<endl;
    after();
    return 0;
}
