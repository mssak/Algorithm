#include<bits/stdc++.h>
#define MAX 300
using namespace std;

int l,x,y,dx,dy;
pair<int,int> mov[8]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};

int bfs(int v[][MAX])
{
    queue<pair<int,int>> q;
    v[x][y]=1;
    q.push({x,y});
    while(true){
        auto [cx,cy]=q.front();
        q.pop();
        if(cx==dx and cy==dy){
            return v[cx][cy];
        }
        for(auto i:mov){
            int nx=i.first+cx;
            int ny=i.second+cy;
            if(nx>=0 and nx<l and ny>=0 and ny<l and v[nx][ny]==0){
                q.push({nx,ny});
                v[nx][ny]=v[cx][cy]+1;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    while(n--){
        int v[MAX][MAX]={};
        cin>>l>>x>>y>>dx>>dy;
        cout<<bfs(v)-1<<"\n";
    }
}