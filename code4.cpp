#include<iostream>
using namespace std;

int m, n, arr[100010], mtime[100010];

int minn() {    //找到当前用时最短的队伍
    int mintime = 1000000, mini;
    for (int i = 0; i < m; i++) {
        if (mtime [i] < mintime) {
            mintime = mtime[i];
            mini = i;
        }
    }
    return mini;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        mtime[minn()] += arr[i];
    }
    int t = mtime[0];
    for (int i = 1; i < m; i++) {  //遍历每个队伍的用时，找到最多的那一组
        if (mtime[i] > t) {
            t = mtime[i];
        }
    }
    cout << t;
    return 0;
}
