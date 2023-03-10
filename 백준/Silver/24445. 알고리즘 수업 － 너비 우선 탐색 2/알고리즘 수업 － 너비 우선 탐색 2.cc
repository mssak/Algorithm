#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;

int ans[MAX]={};

void bfs(int v,vector<int> e[],int r)
{
    int order=0;
    queue<int> q;
    q.push(r);
    ans[r]=++order;

    while(q.size()!=0){
        r=q.front();
        q.pop();        
        for(auto i:e[r]){
            if(!ans[i]){
                ans[i]=++order;
                q.push(i);
            }
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
        e[a].push_back(b);
        e[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end(),greater<>());
    }

    bfs(n,e,r);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<"\n";
    }
}