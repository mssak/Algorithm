#include<bits/stdc++.h>
#define MAX 20
using namespace std;

int r,c,ans=0;
char board[MAX][MAX];
bool chk['Z'-'A'+1]={};
pair<int,int> mov[4]={{1,0},{-1,0},{0,1},{0,-1}};


void dfs(int cx,int cy,int depth)
{
    chk['Z'-board[cy][cx]]=true;
    for(auto i:mov){
        auto [nx,ny]=i;
        nx+=cx;
        ny+=cy;
        if(nx>=0 and nx<c and ny>=0 and ny<r and !chk['Z'-board[ny][nx]]){
            dfs(nx,ny,depth+1);
        }
    }

    chk['Z'-board[cy][cx]]=false;
    ans=max(ans,depth);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>r>>c;

    for(int y=0;y<r;y++){
        for(int x=0;x<c;x++){
            char a;
            cin>>a;
            board[y][x]=a;
        }
    }

    
    dfs(0,0,1);
    cout<<ans;
}