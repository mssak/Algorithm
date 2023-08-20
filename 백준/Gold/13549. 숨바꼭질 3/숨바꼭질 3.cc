#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;
using pii = pair<int,int>;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;

    int dist[MAX];
    for(int i=0;i<MAX;i++){
        dist[i]=1e9;
    }
    dist[n]=0;

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,n});
    
    while(!pq.empty()){
        auto [d,c]=pq.top();
        pq.pop();

        if(c==k){
            cout<<d;
            return 0;
        }
        else if(d>dist[c]){
            continue;
        }
        else{
            if(c-1>=0 && dist[c-1]>d+1){
                dist[c-1]=d+1;
                pq.push({d+1,c-1});
            }
            if(c+1<=MAX-1 && dist[c+1]>d+1){
                dist[c+1]=d+1;
                pq.push({d+1,c+1});
            }
            if(c*2<=MAX-1 && dist[c*2]>d){
                dist[c*2]=d;
                pq.push({d,c*2});
            }
        }
    }
}
