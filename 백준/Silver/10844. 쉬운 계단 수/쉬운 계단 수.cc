#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long dp[100][10]={0,};

    int n;
    cin>>n;

    for(int i=1;i<10;i++){
        dp[0][i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=9;j++){
            if(j-1>=0){
                dp[i][j]+=dp[i-1][j-1];
            }
            if(j+1<=9){
                dp[i][j]+=dp[i-1][j+1];
            }
            dp[i][j]%=1'000'000'000;
        }
    }

    long long s=0;
    for(int i=0;i<10;i++){
        s+=dp[n-1][i];
        s%=1'000'000'000;
    }

    cout<<s;
}