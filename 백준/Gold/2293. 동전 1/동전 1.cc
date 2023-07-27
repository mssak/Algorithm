#include<bits/stdc++.h>
#define MAX 10'001
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int dp[MAX]={0};
    dp[0]=1;
    int n,k;
    cin>>n>>k;

    while(n--){
        int a;
        cin>>a;

        for(int i=a;i<=k;i++){
            dp[i]=dp[i]+dp[i-a];
        }
    }

    cout<<dp[k];
}