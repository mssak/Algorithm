#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 50


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> bus(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        bus[a].push_back({b,c});
    }
    int s,e;
    cin>>s>>e;

    vector<int> dist(n+1,1e9);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,s});
    dist[s]=0;

    while(pq.size()){
        auto [cd,cn]=pq.top();
        pq.pop();
        if(dist[cn]!=cd) continue;

        for(auto [nn,tmpd]:bus[cn]){
            int nd=cd+tmpd;
            if(dist[nn]>nd){
                pq.push({nd,nn});
                dist[nn]=nd;
            }
        }
    }
    cout<<dist[e];
}   