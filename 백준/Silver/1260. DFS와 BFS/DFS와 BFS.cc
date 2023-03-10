#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

bool visited[MAX]={};

void bfs(int v,vector<int> e[],int r)
{
    bool visited[MAX]={};
    queue<int> q;
    q.push(r);
    while(!q.empty()){
        r=q.front();
        cout<<r<<" ";
        q.pop();
        visited[r]=1;
        for(auto i:e[r]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

void dfs(int v,vector<int> e[],int r)
{
    visited[r]=1;
    cout<<r<<" ";
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
        sort(e[i].begin(),e[i].end());
    }

    dfs(n,e,r);
    cout<<"\n";
    bfs(n,e,r);
}