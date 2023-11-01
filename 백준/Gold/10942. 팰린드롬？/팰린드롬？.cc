#include<bits/stdc++.h>
#define MAX 2000
using namespace std;

int dp[MAX][MAX];
int arr[MAX];

bool f(int s,int e){
    if(s>=e){
        return true;
    }
    else if(dp[s][e]!=-1){
        return dp[s][e];
    }
    return dp[s][e]=f(s+1,e-1)&&(arr[s]==arr[e]);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int s,e;
        bool ans=true;
        cin>>s>>e;
        s--;e--;
        cout<<(f(s,e)?1:0)<<"\n";
    }
}
