#include<bits/stdc++.h>
#define MAX 1'000'001
using namespace std;

int node[MAX];
vector<int> edge[MAX];
int dp[MAX][2];
bool v[MAX]{0};

void dfs(int a)
{
    int yes{1},no{0};
    v[a]=true;
    for(int i:edge[a]){
        if(!v[i]){
            dfs(i);
            yes+=min(dp[i][0],dp[i][1]);
            no+=dp[i][1];
        }
    }
    dp[a][0]=no;
    dp[a][1]=yes;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        dp[i][0]=1e9;
        dp[i][1]=1e9;
    }

    dfs(1);
    cout<<min(dp[1][0],dp[1][1]);
}