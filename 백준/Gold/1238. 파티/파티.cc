#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,x;
    int edge[MAX][MAX]{0};
    int dij[MAX];
    int dij2[MAX];
    cin>>n>>m>>x;
    x--;
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        edge[a][b]=c;
    }

    memset(dij,-1,sizeof(dij));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,x});
    while(pq.size()){
        auto[d,cn]=pq.top();
        pq.pop();
        if(dij[cn]!=-1){
            continue;
        }
        dij[cn]=d;

        for(int i=0;i<n;i++){
            if(edge[cn][i]){
                pq.push({d+edge[cn][i],i});
            }
        }
    }

    memset(dij2,-1,sizeof(dij2));
    pq.push({0,x});
    while(pq.size()){
        auto[d,cn]=pq.top();
        pq.pop();
        if(dij2[cn]!=-1){
            continue;
        }
        dij2[cn]=d;

        for(int i=0;i<n;i++){
            if(edge[i][cn]){
                pq.push({d+edge[i][cn],i});
            }
        }
    }

    int mx=-1;
    for(int i=0;i<n;i++){
        if(i==x){
            continue;
        }
        int t=dij[i]+dij2[i];
        mx=max(mx,t);
    }
    cout<<mx;
}