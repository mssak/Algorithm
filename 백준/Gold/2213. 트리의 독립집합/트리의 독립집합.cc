#include<bits/stdc++.h>
#define MAX 10'001
using namespace std;

int node[MAX];
int parent[MAX]{0};
vector<int> edge[MAX];
vector<int> path;

int dp[MAX][2]{0}; //0,1: 본인 비포함,포함

void findParent(int a)
{
    for(int i:edge[a]){
        if(!parent[i]){
            parent[i]=a;
            findParent(i);
        }
    }
}

void findPath(int a,int b)
{
    if(b==0){
        for(int i:edge[a]){
            if(i==parent[a]){
                continue;
            }
            if(dp[i][1]>dp[i][0]){
                findPath(i,1);
            }
            else{
                findPath(i,0);
            }
        }
    }
    else if(b==1){
        path.push_back(a);
        for(int i:edge[a]){
            if(i==parent[a]){
                continue;
            }
            findPath(i,0);
        }
    }
}

int f(int a,int b)
{
    if(dp[a][b]){
        return dp[a][b];
    }

    if(b==0){
        int ans{0};
        for(int i:edge[a]){
            if(i==parent[a]){
                continue;
            }
            ans+=max(f(i,0),f(i,1));
        }
        return dp[a][b]=ans;
    }
    else if(b==1){
        int ans{node[a]};
        for(int i:edge[a]){
            if(i==parent[a]){
                continue;
            }
            ans+=f(i,0);
        }
        return dp[a][b]=ans;
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>node[i];
    }

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    parent[1]=-1;
    findParent(1);

    cout<<max(f(1,1),f(1,0))<<"\n";

    if(dp[1][1]>dp[1][0]){
        findPath(1,1);
    }
    else{
        findPath(1,0);
    }

    sort(path.begin(),path.end());

    for(int i:path){
        cout<<i<<" ";
    }
}