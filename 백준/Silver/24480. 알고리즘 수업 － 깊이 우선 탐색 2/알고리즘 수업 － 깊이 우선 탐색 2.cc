#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;

int visited[MAX]={};
int cnt=0;

void dfs(int v,vector<int> e[],int r)
{
    visited[r]=++cnt;
    for(auto i:e[r]){
        if(!visited[i]){
            dfs(v,e,i);
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> e[MAX];

    int n,m,r;
    cin>>n>>m>>r;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e[b].push_back(a);
        e[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end(),greater<>());
    }

    dfs(n,e,r);

    for(int i=1;i<=n;i++){
        cout<<visited[i]<<"\n";
    }
}