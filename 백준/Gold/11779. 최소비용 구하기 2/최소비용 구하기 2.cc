#include<bits/stdc++.h>
#define MAX 1'001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    int dist[MAX];
    int bef[MAX];
    for(int i=0;i<MAX;i++){
        dist[i]=1e9;
    }

    vector<pair<int,int>> road[MAX];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        road[a].push_back({c,b});
    }
    int s,g;
    cin>>s>>g;

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> q;
    q.push({0,s,-1});
    while(!q.empty()){
        auto [d,c,b]=q.top();
        q.pop();

        if(dist[c]<=d){
            continue;
        }

        dist[c]=d;
        bef[c]=b;
        if(c==g){
            break;
        }

        for(auto i:road[c]){
            q.push({d+i.first,i.second,c});
        }
    }

    cout<<dist[g]<<"\n";
    vector<int> ans;
    int count=0;
    for(int i=g;i!=s;i=bef[i]){
        count++;
        ans.push_back(i);
    }
    ans.push_back(s);
    cout<<count+1<<"\n";

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
}