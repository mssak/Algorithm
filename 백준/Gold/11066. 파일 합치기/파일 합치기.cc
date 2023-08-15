#include<bits/stdc++.h>
#define MAX 500
using namespace std;

int arr[MAX];
int dp[MAX][MAX];
int s[MAX];

int f(int a,int b)
{
    if(dp[a][b]){
        return dp[a][b];
    }
    else if(a==b){
        return 0;
    }
    else{
        dp[a][b]=INT_MAX;
        for(int i=a;i<b;i++){
            dp[a][b]=min(dp[a][b],f(a,i)+f(i+1,b));
        }
        dp[a][b]+=s[b];
        if(a!=0){
            dp[a][b]-=s[a-1];
        }
        return dp[a][b];
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int ss=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            ss+=arr[i];
            s[i]=ss;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=0;
            }
        }

        cout<<f(0,n-1)<<"\n";
    }
}
