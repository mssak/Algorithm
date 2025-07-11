#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 101

int n;
char arr[MAX][MAX];
int diry[4]={1,0,-1,0};
int dirx[4]={0,1,0,-1};

void bfs()
{
    bool v[MAX][MAX]={0,};
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!v[i][j]){
                ans++;
                queue<pair<int,int>> q;
                q.push({i,j});
                v[0][0]=1;

                while(q.size()){
                    auto [y,x]=q.front();
                    q.pop();

                    for(int i=0;i<4;i++){
                        int ny=y+diry[i];
                        int nx=x+dirx[i];
                        if(ny>=0&&ny<n&&nx>=0&&nx<n){
                            if(!v[ny][nx] && arr[ny][nx]==arr[y][x]){
                                q.push({ny,nx});
                                v[ny][nx]=1;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<" ";
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='R'){
                arr[i][j]='G';
            }
        }
    }
    bfs();
}