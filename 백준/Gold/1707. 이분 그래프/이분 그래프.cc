#include<bits/stdc++.h>

using namespace std;

int k,v,e;

void dfs(int a,vector<int> edge[],short chk[],bool flag)
{
    for(int i:edge[a]){
        if(!chk[i]){
            chk[i]=(flag?1:2);
            dfs(i,edge,chk,!flag);
        }
    }
}

bool anschk(vector<int> edge[],short chk[])
{
    for(int i=0;i<v;i++){
        for(int j:edge[i]){
            if(chk[j]==chk[i]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>k;
    while(k--){
        cin>>v>>e;
        vector<int> edge[v];
        short chk[v]={};
        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            a--;b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        for(int i=0;i<v;i++){
            if(!chk[i]){
                chk[i]=2;
                dfs(i,edge,chk,true);
            }
        }

        if(anschk(edge,chk)){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}