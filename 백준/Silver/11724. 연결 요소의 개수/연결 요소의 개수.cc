#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int check[MAX]={};
bool arr[MAX][MAX]={};

void dfs(int i,int n)
{
    for(int j=1;j<=n;j++){
        if(arr[i][j] && !check[j]){
            check[j]=1;
            dfs(j,n);
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,ans=0;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }

    for(int i=1;i<=n;i++){
        if(!check[i]){
            check[i]=1;
            ans++;
            dfs(i,n);
        }
    }
    cout<<ans;
}