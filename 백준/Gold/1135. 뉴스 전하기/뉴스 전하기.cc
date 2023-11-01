#include<bits/stdc++.h>
#define MAX 50
using namespace std;

int dp[MAX];
vector<int> edge[MAX];
int prnt[MAX];
int f(int a)
{
    if(dp[a]!=-1){
        return dp[a];
    }
    else{
        int ans=0;
        
        vector<int> v;
        for(int i:edge[a]){
            v.push_back(f(i));
        }
        
        sort(v.begin(),v.end(),greater<>());
        for(int i=0;i<v.size();i++){
            ans=max(ans,v[i]+i);
        }
        return dp[a]=ans+1;
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>prnt[i];
        if(prnt[i]!=-1){
            edge[prnt[i]].push_back(i);
        }
    }

    memset(dp,-1,sizeof(dp));
    cout<<f(0)-1;
}
