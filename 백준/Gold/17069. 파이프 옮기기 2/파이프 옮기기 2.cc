#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

bool wall[32][32];
ll dp[32][32][3];
ll n;

ll f(ll y,ll x,ll d){
    if(y<0||y>=n||x<0||x>=n||wall[y][x]){
        return 0;
    }
    if(d==1 && y!=0 && x!=0){
        if(wall[y-1][x]||wall[y][x-1]){
            return 0;
        }
    }

    if(dp[y][x][d]!=-1){
        return dp[y][x][d];
    }

    ll ans;
    if(d==0){
        ans = f(y,x-1,0)+f(y,x-1,1);
    }else if(d==1){
        ans = f(y-1,x-1,0)+f(y-1,x-1,1)+f(y-1,x-1,2);
    }else if(d==2){
        ans = f(y-1,x,1)+f(y-1,x,2);
    }

    return dp[y][x][d]=ans;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>wall[i][j];
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
            dp[i][j][2]=-1;
        }
    }

    dp[0][1][0]=1;

    cout<<f(n-1,n-1,0)+f(n-1,n-1,1)+f(n-1,n-1,2);
}
