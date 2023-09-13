#include<bits/stdc++.h>
#define MAX 200
using namespace std;

int n,m;
bool edge[MAX][MAX];
bool v[MAX]{0};
vector<int> goal;

void dfs(int a){
    v[a]=true;

    for(int i=0;i<n;i++){
        if(edge[a][i] && !v[i]){
            dfs(i);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>edge[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        goal.push_back(a);
    }

    dfs(goal[0]-1);

    for(int i:goal){
        i--;
        if(!v[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
