#include<bits/stdc++.h>
#define MAX 500
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[MAX][MAX];
    int dp[MAX][MAX] = {0};

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else if(j == i) {
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[n-1][i]);
    }
    cout << ans;
}
