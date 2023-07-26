#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n{}, k{};
    int dp[100'001]{};
    int v{}, c{};

    cin >> n >> k;
    while (n--) {
        cin >> v >> c;

        for (int i{k}; i >= v; i--) dp[i] = max(dp[i], dp[i - v] + c);
    }

    cout << dp[k];

    return 0;
}