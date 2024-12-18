#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll A, B, K, M;
    cin >> A >> B >> K >> M;
    
    ll cnt = 0;
    ll S = 1;

    for (ll i = 1; i < K; i++) S *= 10;
    ll MUL = S * 10;

    for (ll i = S; i < S * 10; i++) {
        ll x = i;

        while (x <= B) {
            x = x * MUL + i;
        }

        while (x >= i) {
            if (x >= A && x <= B) {
                if (x % M == 0) {
                    cnt++;
                }
            }
            x /= 10;
        }
    }

    cout << cnt << '\n';
    return 0;
}
