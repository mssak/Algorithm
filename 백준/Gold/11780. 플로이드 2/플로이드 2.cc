#include<bits/stdc++.h>
#define MAX 101
#define INF 1e9
using namespace std;

int dis[MAX][MAX];
int pre[MAX][MAX]{0};

void search(int x, int y, vector<int>& dq) {
    int next = pre[x][y];
    if (next == 0) {
        return;
    }

    search(x, next, dq);
    dq.push_back(next);
    search(next, y, dq);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    for(int i=1;i<MAX;i++){
        for(int j=1;j<MAX;j++){
            dis[i][j]=INF;
        }
    }

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        dis[a][b]=min(dis[a][b],c);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i==j||i==k||j==k){
                    continue;
                }
                if(dis[j][k]>dis[j][i]+dis[i][k]){
                    dis[j][k]=dis[j][i]+dis[i][k];
                    pre[j][k]=i;
                }
            }
        }
    }

    //출력
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<(dis[i][j]==INF?0:dis[i][j])<<" ";
        }
        cout<<"\n";
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]==INF){
                cout<<0<<"\n";
                continue;
            }

            vector<int> dq;
            search(i, j, dq);
            dq.push_back(j);

            cout<<dq.size()+1<<" ";
            cout<<i<<" ";
            for(int k:dq){
                cout<<k<<" ";
            }
            cout<<"\n";
        }
    }
}
