#include<bits/stdc++.h>
#define MAX 32001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    vector<int> g[MAX];
    int cnt[MAX]={0};

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        cnt[b]++;
    }

    queue<int> pq;
    int ans=0;
    while(ans!=n){
        for(int i=1;i<=n;i++){
            if(cnt[i]==0){
                pq.push(i);
                cnt[i]=-1;
                for(auto j:g[i]){
                    cnt[j]--;
                }
            }
        }
        cout<<pq.front()<<" ";
        pq.pop();
        ans++;
    }
}