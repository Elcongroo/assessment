#include<iostream>
using namespace std;

int main() {
    long long n;
    int cnt=0;
    char ans[100010];
    cin >> n;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            ans[cnt++] = '^';
        }
        else if (n % 2 == 1) {
            n -= 1;
            ans[cnt++] = '-';
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << ans[i];
    }
    return 0;
}
