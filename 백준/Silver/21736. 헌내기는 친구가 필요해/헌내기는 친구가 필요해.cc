#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    char arr[600][600];
    bool v[600][600]{0};

    int sx,sy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='I'){
                sx=j;
                sy=i;
            }
        }
    }

    int ans=0;
    pair<int,int> dir[4]={{0,-1},{-1,0},{1,0},{0,1}};


    queue<pair<int,int>> q;
    q.push({sy,sx});

    while(q.size()){
        auto [cy,cx]=q.front();
        q.pop();

        
        if(arr[cy][cx]=='P'){
            ans++;
        }

        for(int i=0;i<4;i++){
            int ny=cy+dir[i].first;
            int nx=cx+dir[i].second;

            if(ny>=0 && ny<n && nx>=0 && nx<m && v[ny][nx]==false && arr[ny][nx]!='X'){
                v[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }

    if(ans==0){
        cout<<"TT";
        return 0;
    }
    cout<<ans;
}
