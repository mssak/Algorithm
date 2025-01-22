#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long t = 1LL * n * (n + 1) / 2;
    bool p = t > 1;
    for (long long j = 2; j * j <= t; j++)
        if (t % j < 1) {
            p = 0;
            break;
        }
    if (p) return cout << "NO", 0;
    cout << "YES\n";
    if (n < 2) {
        for (int i = 1; i <= n; i++) cout << i << " ";
        return 0;
    }
    cout << "1 3 2";
    for (int i = 4; i <= n; i++) cout << " " << i;
    return 0;
}
