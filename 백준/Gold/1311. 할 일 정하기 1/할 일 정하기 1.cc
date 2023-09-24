#include<bits/stdc++.h>
#define MAX 20
#define MMAX 1048576 //2**MAX
using namespace std;

int arr[MAX][MAX];
int dp[MMAX][MAX];

int f(int a,int b)
{
    if(dp[a][b]!=1e9){
        return dp[a][b];
    }
    int m=1;
    for(int i=0;i<MAX;i++,m<<=1){
        if(m&a){
            dp[a][b]=min(dp[a][b],f(a-m,b-1)+arr[b][i]);
        }
    }
    return dp[a][b];
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<MMAX;i++){
        for(int j=0;j<MAX;j++){
            dp[i][j]=1e9;
        }
    }
    dp[0][0]=0;

    int nn=pow(2,n);
    cout<<f(nn-1,n-1);
}