#include<bits/stdc++.h>

#define MAX 100'001

using namespace std;

using ll = long long;

int n;
int dp[3];
int arr_row[3];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int j=0; j<3; j++){
        cin >> arr_row[j];
        dp[j] = arr_row[j];
    }

    int max_val = 0;
    
    int max_dp[3];
    int min_dp[3];

    for(int j=0; j<3; j++){
        max_dp[j] = dp[j];
        min_dp[j] = dp[j];
    }

    for(int i=1; i<n; i++){
        int temp_max_dp[3];
        int temp_min_dp[3];

        for(int j=0; j<3; j++){
            cin >> arr_row[j];
        }

        temp_max_dp[0] = arr_row[0] + max(max_dp[0], max_dp[1]);
        temp_max_dp[1] = arr_row[1] + max({max_dp[0], max_dp[1], max_dp[2]});
        temp_max_dp[2] = arr_row[2] + max(max_dp[1], max_dp[2]);

        temp_min_dp[0] = arr_row[0] + min(min_dp[0], min_dp[1]);
        temp_min_dp[1] = arr_row[1] + min({min_dp[0], min_dp[1], min_dp[2]});
        temp_min_dp[2] = arr_row[2] + min(min_dp[1], min_dp[2]);

        for(int j=0; j<3; j++){
            max_dp[j] = temp_max_dp[j];
            min_dp[j] = temp_min_dp[j];
        }
    }

    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << "\n";
    cout << min({min_dp[0], min_dp[1], min_dp[2]}) << "\n";

    return 0;
}