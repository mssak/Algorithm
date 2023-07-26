#include<bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    while(true){
        int n{}, k{};
        int dp[10'001]{};
        int v{}, c{};
        double d;

        cin >> n >> d;

        if(n==0 and d==0.00){
            return 0;
        }

        k=d*100+0.5;

        while (n--) {
            cin >> c >> d;

            v=d*100+0.5;

            for (int i{v}; i <= k; i++){
                dp[i] = max(dp[i], dp[i - v] + c);
            }
        }

        cout << dp[k]<<"\n";
    }

    return 0;
}