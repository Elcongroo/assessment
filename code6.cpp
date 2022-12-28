#include<iostream>
#include<math.h>
using namespace std;
int a,b,c,d,ansa,ansb,ansc,ansd;

int check(){
    if(a>=ansa&&b>=ansb&&c>=ansc&&d>=ansd)
        return 1;
    else
        return 0;
}

void find(int a1,int b1,int c1,int d1){
    ansa=a1+b1/3+c1/3+d1/2;
    ansb=b1+a1/3+c1/3+d1/2;
    ansc=c1+a1/3+b1/3+d1/2;
    ansd=d1+a1/2+b1/2+c1/2;
    if(check()){
        cout<<a1<<" "<<b1<<" "<<c1<<" "<<d1;
        return;
    }
    
}

int main(){
    cin>>a>>b>>c>>d;
    find(0,0,0,0);
    return 0;
}
