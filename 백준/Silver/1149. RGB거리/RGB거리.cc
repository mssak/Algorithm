#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int dp[MAX][3]={};

    int n;
    cin>>n;

    for(int i=0;i<3;i++){
        cin>>dp[0][i];
    }


    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            int c;
            cin>>c;
            for(int k=0;k<3;k++){
                if(k==j){
                    continue;
                }
                else if(dp[i][j]==0){
                    dp[i][j]=dp[i-1][k]+c;
                }
                else{
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+c);
                }
            }
        }
    }

    cout<<*min_element(dp[n-1], dp[n-1] + 3);
}