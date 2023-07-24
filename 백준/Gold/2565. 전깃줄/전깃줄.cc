#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    vector<pair<int,int>> arr;
    int dp[501];

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});

        dp[i]=1;
    }

    sort(arr.begin(),arr.end());

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i].second>arr[j].second && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }

    cout<<n-*max_element(dp,dp+n);
}