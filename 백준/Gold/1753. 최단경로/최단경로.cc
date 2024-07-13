#include<bits/stdc++.h>
#define MAX 20'001
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int v,e,k;
    cin>>v>>e>>k;

    vector<pair<int,int>> g[MAX];
    int dist[MAX];

    for (int i = 1; i <= v; i++) {
    dist[i] = INT_MAX;
    }

    dist[k]=0;

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({w,v});
    }
    
    set<pair<int,int>> q;
    q.insert({0,k});

    while(!q.empty()){
        pair<int,int> c=*q.begin();
        q.erase(q.begin());

        if(c.first>dist[c.second]){
            continue;
        }
        
        for(auto i:g[c.second]){
            if(dist[c.second]+i.first<dist[i.second]){
                dist[i.second]=dist[c.second]+i.first;
                q.insert({dist[i.second],i.second});
            }
        }
    }

    for(int i=1;i<=v;i++){
        if(dist[i]==INT_MAX){
            cout<<"INF"<<"\n";
        }
        else{
            cout<<dist[i]<<"\n";
        }
    }
}
