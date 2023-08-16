#include<bits/stdc++.h>
#define MAX 100
#define MAX2 10'001
using namespace std;

int dp[MAX][MAX2];
int mm[MAX];
int cc[MAX];

int f(int a,int b)
{
    if(a<0 or b<0){
        return 0;
    }
    else if(dp[a][b]!=-1){
        return dp[a][b];
    }
    else{
        dp[a][b]=0;
        if(a>0){
            dp[a][b]=max(dp[a][b],f(a-1,b));
        }
        if(cc[a]<=b){
            dp[a][b]=max(dp[a][b],f(a-1,b-cc[a])+mm[a]);
        }
        return dp[a][b];
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++){
        cin>>mm[i];
    }
    for(int i=0;i<n;i++){
        cin>>cc[i];
    }


    int r=INT_MAX;
    for(int i=0;i<MAX2;i++){
        if(f(n-1,i)>=m){
            r=min(r,i);
        }
    }

    cout<<r;
}
