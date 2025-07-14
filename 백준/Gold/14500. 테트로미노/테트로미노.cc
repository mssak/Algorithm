#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 501

int ans=0;
int arr[MAX][MAX];
int n,m;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> tet[19]={
        {
            {1,1,1,1},
        },
        {
            {1},
            {1},
            {1},
            {1}
        },
        {
            {1,1},
            {1,1}
        },
        {
            {1,0},
            {1,0},
            {1,1}
        },
        {
            {1,1},
            {0,1},
            {0,1}
        },
        {
            {0,1},
            {0,1},
            {1,1}
        },
        {
            {1,1},
            {1,0},
            {1,0}
        },
        {
            {1,1,1},
            {0,0,1}
        },
        {
            {1,1,1},
            {1,0,0}
        },
        {
            {1,0,0},
            {1,1,1}
        },
        {
            {0,0,1},
            {1,1,1}
        },
        {
            {1,0},
            {1,1},
            {0,1}
        },
        {
            {0,1},
            {1,1},
            {1,0}
        },
        {
            {0,1,1},
            {1,1,0}
        },
        {
            {1,1,0},
            {0,1,1}
        },
        {
            {1,1,1},
            {0,1,0}
        },
        {
            {0,1,0},
            {1,1,1}
        },
        {
            {1,0},
            {1,1},
            {1,0}
        },
        {
            {0,1},
            {1,1},
            {0,1}
        },
    };

    for(int t=0;t<19;t++){
        auto &v=tet[t];
        int a=v.size();
        int b=v[0].size();

        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                if(y+a<=n&&x+b<=m){
                    int sm=0;
                    for(int i=0;i<a;i++){
                        for(int j=0;j<b;j++){
                            if(v[i][j]){
                                sm+=arr[y+i][x+j];
                            }
                        }
                    }
                    ans=max(sm,ans);
                }
            }
        }
    }
    cout<<ans;
}