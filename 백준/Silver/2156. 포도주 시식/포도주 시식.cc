#include<bits/stdc++.h>
#define MAX 10'000
using namespace std;

int dp[MAX];
int arr[MAX];

int f(int a)
{
    if(a<0){
        return 0;
    }
    else if(dp[a]==-1){
        dp[a]=max({arr[a]+arr[a-1]+f(a-3),f(a-2)+arr[a],f(a-1)});
    }
    return dp[a];
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        dp[i]=-1;
    }
    dp[0]=arr[0];

    cout<<f(n-1);
}