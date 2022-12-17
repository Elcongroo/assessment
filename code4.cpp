#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n,arr[100010],total;
    cin>>m>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total+=arr[i];
    }
    int ans=total/3;
    if(1.0*total/3>ans)
        cout<<ans+1;
    else
        cout<<ans;

    return 0;
}
