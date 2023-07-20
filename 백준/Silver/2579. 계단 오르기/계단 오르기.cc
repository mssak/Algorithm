#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int dp[302][2]={};     //0=1계단올라감, 1=2계단올라감

    int a;
    cin>>a;

    for(int i=2;i<=a+1;i++){
        int c;
        cin>>c;

        dp[i][0]=dp[i-1][1]+c;
        dp[i][1]=max(dp[i-2][0],dp[i-2][1])+c;
    }

    cout<<max(dp[a+1][0],dp[a+1][1]);
}