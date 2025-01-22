#include <bits/stdc++.h>
#define MAX
using namespace std;
using ll = long long;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n, p;
    cin >> n >> p;

    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        ans %= p;
    }

    cout << ans;
}
