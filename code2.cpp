#include<bits/stdc++.h>
using namespace std;

int arr[10][10],q[1001];
int m,n;
int vis[10][10]={0};//�жϸ��������ޱ����ʹ������ж��Ƿ�ת��

void create(){  //����һ�����m*n����
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

char check(int *i,int *j,int x,int y){  //��⵱ǰ�Ƿ�Ӧ��ת��
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
void move(){   //�Ȱ���˳ʱ��˳��Ѷ�ά������뵽һά����q�У��������Ȼ�������°���˳���arr��ֵ
    int order=0,i=0,j=0,x=1,y=0;
    while(order<m*n){
       // cout<<"λ��"<<i<<" "<<j<<endl;
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
    for(i=m*n;i>0;i--)  //����
        q[i]=q[i-1];
    q[0]=q[m*n];
   //  cout<<"test2: ";
   // for(i=0;i<m*n;i++){
   //     cout<<q[i]<<" ";
   // }
    order=0;
    initvis();
    i=0,j=0;
    x=1,y=0;//����ĵط���
    while(order<m*n){
       // cout<<"λ��"<<i<<" "<<j<<endl;
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

