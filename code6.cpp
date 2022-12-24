#include<iostream>
#include<math.h>
using namespace std;
int a,b,c,d,ansa,ansb,ansc,ansd;

int check(){
    if(a==ansa&&b==ansb&&c==ansc&&d==ansd)
        return 1;
    else
        return 0;
}

void dfs(int a1,int b1,int c1,int d1){
    ansa=a1+(int)cbrt(b1)+(int)cbrt(c1)+(int)sqrt(d1);
    ansb=b1+(int)cbrt(a1)+(int)cbrt(c1)+(int)sqrt(d1);
    ansc=c1+(int)cbrt(a1)+(int)cbrt(b1)+(int)sqrt(d1);
    ansd=d1+(int)sqrt(a1)+(int)sqrt(b1)+(int)sqrt(c1);
    if(check()){
        cout<<a1<<" "<<b1<<" "<<c1<<" "<<d1;
        return;
    }
    else{
        for(int i=a1;i<a;i++){
            dfs(i,b1,c1,d1);
            for(int j=b1;j<b;j++){
                dfs(i,j,c1,d1);
                for(int k=c1;k<c;k++){
                    dfs(i,j,k,d1);
                    for(int l=d1;l<d;l++){
                        dfs(i,j,k,l);
                    }
                }
            }
        }
    }
}

int main(){
    cin>>a>>b>>c>>d;
    dfs(0,0,0,0);

    return 0;
}
