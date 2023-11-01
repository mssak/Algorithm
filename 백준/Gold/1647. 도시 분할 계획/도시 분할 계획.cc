#include<bits/stdc++.h>
#define MAX 100'000
using namespace std;

int uf[MAX];

int f(int a){
    if(a==uf[a]){
        return a;
    }
    return uf[a]=f(uf[a]);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    deque<tuple<int,int,int>> dq;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        dq.push_back({c,a,b});
    }

    for(int i=0;i<n;i++){
        uf[i]=i;
    }

    sort(dq.begin(),dq.end(),greater<>());
    int ans=0;
    int cnt=0;
    while(cnt<n-2){
        auto [c,a,b]=dq.back();
        dq.pop_back();
        if(f(a)==f(b)) continue;
        uf[f(a)]=f(b);
        cnt++;
        ans+=c;
    }
    cout<<ans;
}