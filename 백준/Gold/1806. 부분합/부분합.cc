#include<bits/stdc++.h>
#define MAX 100'000
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,s,arr[MAX];
    int dp[MAX]{0};
    cin>>n>>s;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int l=0,h=0,su=arr[0],ans=n+1;
    while(l<=h && h<n){
        if(su>=s){
            ans=min(ans,h-l+1);
            su-=arr[l++];
            continue;
        }
        else{
            su+=arr[++h];            
        }
    }
    if(ans==n+1){
        cout<<0;
    }
    else{
        cout<<ans;
    }
}