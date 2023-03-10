#include<bits/stdc++.h>
#define MAX 100
using namespace std;

short board[MAX][MAX]={};
int ans=0;
int n,m,c,k;

pair<int,int> mov[4]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int y,int x)
{
    c++;
    board[y][x]=2;
    for(auto i:mov){
        auto [ny,nx]=i;
        ny+=y;
        nx+=x;
        if(nx>=0 and nx<m and ny>=0 and ny<n and board[ny][nx]==1){
            dfs(ny,nx);
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        a--;b--;
        board[a][b]=1;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1){
                c=0;
                dfs(i,j);
                ans=max(ans,c);
            }
        }
    }
    cout<<ans;
}