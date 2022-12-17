#include<bits/stdc++.h>
using namespace std;

long long n,result,num;
long long a[10010];
int vis[10010];

int isprime(long long x){
    if(x==1||x==0) return 0;
    if(x==2) return 1;
    for(long long i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int cnt;
void dfs(long long x){
    if(result==n){
        cout<<n<<" "<<"="<<" ";
        for(int j=0;j<num-1;j++){
            cout<<a[j]<<" "<<"+"<<" ";
        }
        cout<<a[num-1];
        cnt=1;
    }

    for(int i=1;i<n;i++){
        if(!vis[i]&&isprime(i)){
            a[num++]=i;
            result+=i;
            vis[i]=1;
            dfs(x+1);
            if(cnt==1) break;
            vis[i]=0;
            num--;
            result-=i;
        }
    }
    return;
}

int main(){
    cin>>n;
    dfs(1);
    return 0;
}
