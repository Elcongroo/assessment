#include<iostream>
using namespace std;

string bir;
long long ans;
int n;
void move(){
    string str;
    for(int i=0;i<n;i++){
        str[i]=bir[(n+i-2)%n];
    }
    for(int i=0;i<n;i++){
        bir[i]=str[i];
    }
    return;
}

void transform(){
    int t;
    for(int i=0;i<n;i++){
        if(bir[n-i]>='0'&&bir[n-i]<='9'){
            t=(int)bir[n-i];
        }
        else{
            t=bir[i]-'A'+10;
        }
        ans=ans*16+t;
    }
    ans=ans*16-5;
    return;
}


int main(){
    cin>>bir;
    n=bir.size();
    move();
    transform();
    cout<<ans;

    return 0;
}
