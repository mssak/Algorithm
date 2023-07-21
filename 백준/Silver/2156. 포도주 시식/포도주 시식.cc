#include<bits/stdc++.h>
#define MAX 10'000
using namespace std;

int dp[MAX];
int arr[MAX];

int fm(int a)
{
    int m=0;
    for(int i=0;i<=a;i++){
        m=max(m,dp[i]);
    }
    return m;
}

int f(int a)
{
    if(dp[a]==-1){
        dp[a]=max(arr[a-1]+fm(a-3),fm(a-2))+arr[a];
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
    if(n>=2){
        dp[1]=dp[0]+arr[1];
    }
    if(n>=3){
        dp[2]=max(arr[0],arr[1])+arr[2];
    }

    for(int i=3;i<n;i++){
        f(i);
    }

    cout<<*max_element(dp,dp+n);
}