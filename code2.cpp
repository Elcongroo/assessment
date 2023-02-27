#include<bits/stdc++.h>
using namespace std;

int arr[10][10],q[1001];
int m,n;
int vis[10][10]={0};//判断该数字有无被访问过，即判断是否转向

void create(){  //创建一个随机m*n矩阵
    int cnt=0;
    srand((int)time(NULL));
    m=rand()%6+2;
    n=rand()%6+2;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=rand()%10;
        }
    }
    return ;
}

void myprint(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

char check(int *i,int *j,int x,int y){  //检测当前是否应该转向
    int ti=*i,tj=*j;
    if(tj>=n&&x==1||(vis[ti][tj]&&x==1)){
        *i-=y;
        *j-=x;
        return 'd';
    }

    if(tj<0&&x==-1||(vis[ti][tj]&&x==-1)){
        *i-=y;
        *j-=x;
        return 'u';
    }

    if(ti>=m&&y==1||(vis[ti][tj]&&y==1)){
        *i-=y;
        *j-=x;
        return 'l';
    }
    if(ti<0&&y==-1||(vis[ti][tj]&&y==-1)){
        *i-=y;
        *j-=x;
        return 'r';
    }
    return 'o';
}

void initvis(){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            vis[i][j]=0;
        }
    }
    return;
}
void move(){   //先按照顺时针顺序把二维数组读入到一维数组q中，进行移项，然后再重新按照顺序对arr赋值
    int order=0,i=0,j=0,x=1,y=0;
    while(order<m*n){
       // cout<<"位置"<<i<<" "<<j<<endl;
        q[order++]=arr[i][j];
        vis[i][j]=1;
        i+=y,j+=x;
        char direction=check(&i,&j,x,y);
        if(direction=='d'){
            x=0;y=1;
        }
        else if(direction=='r'){
            x=1;y=0;
        }
        else if(direction=='l'){
            x=-1;y=0;
        }
        else if(direction=='u'){
            x=0;y=-1;
        }
        else{
            continue;
        }
        i+=y,j+=x;
    }
    int t;
   //  cout<<"test2: ";
   //  for(i=0;i<m*n;i++){
   //     cout<<q[i]<<" ";
   // }
   // cout<<endl;
    for(i=m*n;i>0;i--)  //移项
        q[i]=q[i-1];
    q[0]=q[m*n];
   //  cout<<"test2: ";
   // for(i=0;i<m*n;i++){
   //     cout<<q[i]<<" ";
   // }
    order=0;
    initvis();
    i=0,j=0;
    x=1,y=0;//出错的地方。
    while(order<m*n){
       // cout<<"位置"<<i<<" "<<j<<endl;
        arr[i][j]=q[order++];
        vis[i][j]=1;
        i+=y,j+=x;
        char direction=check(&i,&j,x,y);
        if(direction=='d'){
            x=0;y=1;
        }
        else if(direction=='r'){
            x=1;y=0;
        }
        else if(direction=='l'){
            x=-1;y=0;
        }
        else if(direction=='u'){
            x=0;y=-1;
        }
        else{
            continue;
        }
        i+=y,j+=x;
    }
    cout<<endl;
}

int main(){
    create();
    cout<<m<<" "<<n<<endl;
    cout<<"first:"<<endl;
    myprint();
    cout<<endl;
    cout<<"after:"<<endl;
    move();
    myprint();
    return 0;
}

