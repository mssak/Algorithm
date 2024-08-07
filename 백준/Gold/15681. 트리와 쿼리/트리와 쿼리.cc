#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;

vector<int> tree[MAX];
int sub[MAX]{0};

int dfs(int r)
{
    sub[r]=1;

    for(int i:tree[r]){
        if(!sub[i]){
            sub[r]+=dfs(i);
        }
    }

    return sub[r];
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,r,q;
    cin>>n>>r>>q;

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(r);

    for(int i=0;i<q;i++){
        int a;
        cin>>a;
        cout<<sub[a]<<"\n";
    }
}
