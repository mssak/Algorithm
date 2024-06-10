#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    int arr[301][301];
    int sum[301][301];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            sum[i][j]=arr[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        }
    }

    int k;
    cin>>k;    
    while(k--){
        int i,j,x,y;
        cin>>i>>j>>x>>y;
        cout<<sum[x][y]-sum[x][j-1]-sum[i-1][y]+sum[i-1][j-1]<<"\n";
    }
}