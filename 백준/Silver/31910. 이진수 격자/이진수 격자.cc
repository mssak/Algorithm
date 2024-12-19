#include<bits/stdc++.h>
#define MAX 31
using namespace std;
using ll = long long;

string arr[MAX][MAX];
string dp[MAX][MAX];
ll n;
vector<string> vs;

string f(ll y,ll x){
    if(y>=n||x>=n){
        return string();
    }
    if(dp[y][x]!="0"-1){
        return dp[y][x];
    }

    else{
        return dp[y][x]=arr[y][x]+max(f(y,x+1),f(y+1,x));
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin>>n;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>arr[i][j];
            dp[i][j]="0"-1;
        }
    }

    f(0,0);

    string s = dp[0][0];

    ll ans=0;
    ll po=1;
    for(ll i=s.length()-1;i>=0;i--){
        ans+=(s[i]-'0')*po;
        po*=2;
        // cout<<ans<<"\n";
    }

    cout<<ans;
}
