#include<bits/stdc++.h>
#define MAX 500 
using namespace std;

int dp[MAX][MAX];
int mat[MAX][2];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        mat[i][0]=a;
        mat[i][1]=b;
    }

    for(int i=1;i<n;i++){
        for(int j=0;i+j<n;j++){
            dp[j][i+j]=INT_MAX;
            for(int k=j;k<i+j;k++){
                dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+mat[j][0]*mat[k][1]*mat[i+j][1]);
            }
        }
    }


    cout<<dp[0][n-1];

}