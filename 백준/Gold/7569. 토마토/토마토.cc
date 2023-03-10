#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int h,m,n,ans=0,cnt=0,no=0;
int v[MAX][MAX][MAX];
tuple<int,int,int> mov[6]={{-1,0,0},{1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

int bfs()
{
    queue<tuple<int,int,int>> q;

    for(int z=0;z<h;z++){
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                if(v[z][y][x]==1){
                    q.push({z,y,x});
                    cnt++;
                }
                else if(v[z][y][x]==-1){
                    no++;
                }
            }
        }
    }
    if(cnt==m*n*h-no){
        return 0;
    }

    while(!q.empty()){
        int siz=q.size();
        for(int i=0;i<siz;i++){
            auto [z,y,x]=q.front();
            q.pop();
            for(auto j:mov){
                auto [nz,ny,nx]=j;
                nz+=z;
                ny+=y;
                nx+=x;

                if(nx>=0 and nx<m and ny>=0 and ny<n and nz>=0 and nz<h and v[nz][ny][nx]==0){
                    v[nz][ny][nx]=1;
                    q.push({nz,ny,nx});
                    cnt++;
                }
            }
        }
        ans++;
    }

    if(cnt==m*n*h-no){
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

    cin>>m>>n>>h;

    for(int z=0;z<h;z++){
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                int a;
                cin>>a;
                v[z][y][x]=a;
            }
        }
    }

    cout<<bfs();
}