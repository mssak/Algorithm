#include<bits/stdc++.h>
#define MAX 101
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[MAX][MAX];
    
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]=1e9;
        }
    }
    for(int i=1;i<=n;i++){
        arr[i][i]=0;
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a][b]=min(c,arr[a][b]);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<(arr[i][j]==1e9?0:arr[i][j])<<" ";
        }
        cout<<"\n";
    }
}
