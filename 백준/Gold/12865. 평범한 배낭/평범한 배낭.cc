#include<bits/stdc++.h>
using namespace std;

pair<int,int> arr[101];
int dp[101][100'001]={0};

int f(int a,int w)
{
    if(w<0){
        return INT_MIN;
    }
    else if(a<0 or w==0){
        return 0;
    }
    else if(dp[a][w]){
        return dp[a][w];
    }
    else{
        dp[a][w]=max(f(a-1,w),f(a-1,w-arr[a].first)+arr[a].second);
        return dp[a][w];
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[i]={a,b};
    }

    f(n,k);
    cout<<dp[n][k];
}