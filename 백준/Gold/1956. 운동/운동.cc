#include<bits/stdc++.h>
#define MAX 400
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[MAX][MAX];
    int v,e;
    cin>>v>>e;
    v;e;

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            arr[i][j]=INT_MAX;
        }
    }

    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;c;
        arr[a][b]=c;
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                if(arr[j][i]==INT_MAX||arr[i][k]==INT_MAX||j==i||k==i){
                    continue;
                }
                arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
            }
        }
    }

    int ans=INT_MAX;
    for(int i=0;i<v;i++){
        ans=min(ans,arr[i][i]);
    }

    cout<<(ans==INT_MAX?-1:ans);
}
