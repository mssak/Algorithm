#include <bits/stdc++.h>
#define MAX 10'000
using namespace std;
using ll = long long;

bool notPri[1'000'001] = {0};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    // 에라토스테네스의 체
    for (int i = 2; i * i <= 1'000'000; i++) {
        if (!notPri[i]) {
            for (int j = i * i; j <= 1'000'000; j += i) {
                notPri[j] = 1;
            }
        }
    }

    set<int> primes;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (!notPri[a]) {
            primes.insert(a);
        }
    }

    if (primes.empty()) {
        cout << -1;
    } else {
        ll ans = 1;
        for (int prime : primes) {
            ans *= prime;
        }
        cout << ans;
    }

    return 0;
}
