#include<bits/stdc++.h>

using namespace std;

int arr[1000];
int dp[1000]={};

int f(int a)
{
    if(dp[a]){
        return dp[a];
    }
    else{
        dp[a]=arr[a];
        for(int i=0;i<a;i++){
            if(arr[i]<arr[a]){
                dp[a]=max(f(i)+arr[a],dp[a]);
            }
        }
        return dp[a];
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;

    for(int i=0;i<a;i++){
        cin>>arr[i];
    }

    for(int i=0;i<a;i++){
        f(i);
    }

    int ans=0;
    for(int i=0;i<a;i++){
        ans=max(dp[i],ans);
    }
    cout<<ans;
}