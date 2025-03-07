#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,k;
    cin>>n>>m>>k;
    k--;
    vector<vector<pii>> v(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;

        v[a].push_back({b,c});
    }

    vector<int> dist(n+1);
    for(int i=0;i<n;i++){
        dist[i]=1e9;
    }
    priority_queue<pii,vector<pii>,greater<>> pq;
    pq.push({0,k});
    
    while(pq.size()){
        auto [d,c]=pq.top();
        pq.pop();
        if(d>dist[c]){
            continue;
        }
        dist[c]=d;

        for(auto [to,dt]:v[c]){
            if(dt+d<dist[to]){
                dist[to]=dt+d;
                pq.push({dt+d,to});
            }
        }
    }

    for(int i=0;i<n;i++){
        if(dist[i]==1e9){
            cout<<"INF"<<"\n";
        }else{
        cout<<dist[i]<<"\n";
        }
    }
}
