#include<iostream>
using namespace std;

string s,s1,s2,str,aimstr;
int n=s.size();

int check(string str,int x){
    for(int i=0;i<str.size();i++){
        if(s[i+x]!=str[i]){
            return 0;
        }
    }
    return 1;
}

int place1(){
    for(int i=0;i<s.size();i++){
        if(check(s1,i)){
            return i;
        }
    }
    return 105;
}
int place2(){
    for(int i=0;i<s.size();i++){
        if(check(s2,i)){
            return i;
        }
    }
    return 105;
}

string find(int head,int tail){
    if(head<tail){
        for(int i=head+1;i<tail;i++){
            aimstr+=s[i];
        }
    }
    else{
        for(int i=head-1;i>tail;i--){
            aimstr+=s[i];
        }
    }
}



int main(){
    cin>>s1>>s2>>s;
    if(s2<s1){
        str=s2;
        s2=s1;
        s1=str;
    }
    if(place1()>100||place2()>100){
        cout<<"ERROR";
        return 0;
    }
    if(abs(place1()-place2())==s2.size()||abs(place1()-place2())==s1.size()){
        cout<<"NONE";
        return 0;
    }
    int head,tail;
    if(place1()>place2()){
        head=place1();
        tail=place2()+s2.size();
        find(head,tail);
    }
    else{
        head=place2();
        tail=place1()+s1.size();
        find(head,tail);
    }
    cout<<aimstr;
    return 0;
}
