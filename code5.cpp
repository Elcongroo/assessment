#include<iostream>
using namespace std;

string bir(100,0);
long long ans;
int n;
void move() {
    string str(100,0);
    for (int i = 0; i < n; i++) {
        str[i] = bir[(n + i - 2) % n];
    }
    for (int i = 0; i < n; i++) {
        bir[i] = str[i];
    }
    return;
}
void scale() {
    for (int i = 0; i < n; i++) {
        if (bir[i] >= '0' && bir[i] <= '9') {
            ans = ans * 16 + bir[i] - '0';
        }
        else {
            ans = ans * 16 + bir[i] - 'A' + 10;
        }
    }
    return;
}

void transform() {
    for (int i = 0; i < n; i++) {
        if (bir[i] >= '5' && bir[i] <= '9') {
            bir[i] = bir[i] - 5;
        }
        else if (bir[i] >= '0' && bir[i] < '5') {
            bir[i] = 'F' - 4 + bir[i] - '0';
        }
        else if (bir[i] >= 'A' && bir[i] < 'F') {
            bir[i] = '9' - (4 - bir[i] + 'A');
        }
        else {
            bir[i] = 'A';
        }
    }

    scale(); //进制转化
    return;
}

void myprint() {
    int year = ans / 10000;
    int month = ans / 100 % 100;
    int day = ans % 100;
    cout << year << "年" << month << "月" << day << "日";
    return;
}

int main() {
    cin >> bir;
    n = bir.size();
    move();  //执行位置转换的操作
    transform();  //进行-5操作
    myprint();  //输出答案
    return 0;
}
