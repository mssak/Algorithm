#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int m,n,ans=0,cnt=0,no=0;
int v[MAX][MAX];
pair<int,int> mov[4]={{-1,0},{1,0},{0,1},{0,-1}};

int bfs()
{
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==1){
                q.push({i,j});
                cnt++;
            }
            else if(v[i][j]==-1){
                no++;
            }
        }
    }
    if(cnt==m*n-no){
        return 0;
    }

    while(!q.empty()){
        int siz=q.size();
        for(int i=0;i<siz;i++){
            auto [y,x]=q.front();
            q.pop();
            for(auto j:mov){
                int nx=x+j.second;
                int ny=y+j.first;
                if(nx>=0 and nx<m and ny>=0 and ny<n and v[ny][nx]==0){
                    v[ny][nx]=1;
                    q.push({ny,nx});
                    cnt++;
                }
            }
        }
        ans++;
    }

    if(cnt==m*n-no){
        return ans-1;
    }
    else{
        return -1;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>m>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            v[i][j]=a;
        }
    }

    cout<<bfs();
}