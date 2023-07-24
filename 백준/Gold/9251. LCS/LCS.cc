#include<bits/stdc++.h>
#define MAX 1'001
using namespace std;

int dp[MAX][MAX]={0};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s1,s2;
    cin>>s1>>s2;

    int s1s=s1.size();
    int s2s=s2.size();

    for(int i=1;i<=s1s;i++){
        for(int j=1;j<=s2s;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout<<dp[s1s][s2s];
}