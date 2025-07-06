#include<bits/stdc++.h>
#define MAX 101
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    int dist[MAX][MAX];
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=1e9;
        }
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        dist[a][b]=dist[b][a]=1;
    }

    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }

    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    int mn=1e9;
    int ans;
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=n;j++){
            tmp+=dist[i][j];
        }
        if(tmp<mn){
            ans=i;
            mn=tmp;
        }
    }

    cout<<ans;
}