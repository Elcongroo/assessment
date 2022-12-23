#include<iostream>
using namespace std;

string s,s1,s2,str,aimstr,aimstr2,aimstr3;
int n=s.size();


int check(string str,int x){  //判断从s[x]开始是否与对应字符串相同
    for(int i=0;i<str.size();i++){
        if(s[i+x]!=str[i]){
            return 0;
        }
    }
    return 1;
}

int place1(){     //head的头字母位置
    for(int i=0;i<s.size();i++){
        if(check(s1,i)){
            return i;
        }
    }
    return 105;
}
int place2(){   //tail的头字母位置
    for(int i=0;i<s.size();i++){
        if(check(s2,i)){
            return i;
        }
    }
    return 105;
}

string find(int head,int tail){  //找到aimstr
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

void mytransform(){
    for(int i=0;i<aimstr2.size();i++){
        if(aimstr2[i]>='a'&&aimstr2[i]<='z'){
            aimstr2[i]-=32;
        }
        else{
            aimstr2[i]+=32;
        }
    }
}

void mydelete(){
    for(int i=0;i<aimstr.size();i++){
        if(aimstr[i]>='a'&&aimstr[i]<='z'||aimstr[i]>='A'&&aimstr[i]<='Z'){
            aimstr2+=aimstr[i];
        }
    }
}

void ascii(){
    int a[101];
    string b[101];
    for(int i=0;i<aimstr2.size();i++){
        a[i]=aimstr2[i];
        if(a[i]<100&&i!=0||i==aimstr2.size()-1&&a[i]%10==0){
           b[i]="0"+to_string(aimstr2[i]);
        }
        else{
            b[i]=to_string(aimstr2[i]);
        }
    }
    for(int i=0;i<aimstr2.size();i++){
        aimstr3+=b[i];
    }
}

int mystrlen(char *str){
    if(*str=='\0')
        return 0;
    else
        return mystrlen(str+1)+1;
}

void reverse(char *string){  //递归反转字符串需要结合mystrlen()函数
    int len=mystrlen(string);
    if(len<=1)
        return;
    else{
        char temp=string[0];
        string[0]=string[len-1];
        string[len-1]='\0';
        reverse(string+1);
        string[len-1]=temp;
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
        tail=place2()+s2.size()-1;
        find(head,tail);
    }
    else{
        head=place1()+s1.size()-1;
        tail=place2();
        find(head,tail);
    }
    mydelete();
    mytransform();
    ascii();
    reverse(&aimstr3[0]);
    cout<<aimstr3;
    return 0;
}
