#include<bits/stdc++.h>
#define MAX 101
using namespace std;

bool visited[MAX]={};
int cnt=0;

void dfs(int v,vector<int> e[],int r)
{
    visited[r]=1;
    cnt++;
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

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e[b].push_back(a);
        e[a].push_back(b);
    }

    dfs(n,e,1);

    cout<<cnt-1;
}