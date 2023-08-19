#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ppi = pair<int,int>;

int n,e,u,v;
vector<vector<ppi>> g;

int dijkstra(int s,int e)
{
    vector<int> dist(n+1);
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }    
    dist[s]=0;

    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    pq.push({0,s});

    while(!pq.empty()){
        auto [cd,cn]=pq.top();
        pq.pop();

        if(cn==e){
            return cd;
        }

        if(dist[cn]<cd){
            continue;
        }

        for(auto i:g[cn]){
            auto [nd,nn]=i;
            if(dist[nn]>cd+nd){
                dist[nn]=cd+nd;
                pq.push({cd+nd,nn});
            }
        }
    }

    return INT_MIN;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>e;

    g.resize(n+1);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({c,b});
        g[b].push_back({c,a});
    }
    cin>>u>>v;
    
    int ans1=dijkstra(1,u)+dijkstra(u,v)+dijkstra(v,n);
    int ans2=dijkstra(1,v)+dijkstra(v,u)+dijkstra(u,n);
    int ans;

    if (ans1 >= 0 && ans2 >= 0) {
        ans = (ans1 < ans2) ? ans1 : ans2;
    } else if (ans1 >= 0) {
        ans = ans1;
    } else if (ans2 >= 0) {
        ans = ans2;
    } else {
        // 둘 다 음수인 경우의 처리
        ans = -1; // 혹은 다른 적절한 값
    }

    cout<<ans;
}