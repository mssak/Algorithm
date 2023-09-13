#include<bits/stdc++.h>
using namespace std;

int uf[10'001];

struct Edge{
    int a,b,c;
    bool operator<(const Edge right)const{
        if(c<right.c) return true;
        else return false;
    }
};

int find(int a)
{
    if(a==uf[a]){
        return a;
    }
    return find(uf[a]);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int v,e;
    cin>>v>>e;

    for(int i=1;i<=v;i++){
        uf[i]=i;
    }

    Edge edge[100'000];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;

        edge[i]={a,b,c};
    }
    sort(edge,edge+e);

    int cnt=0;
    int ans=0;
    for(int i=0;cnt!=v-1;i++){
        auto[a,b,c] = edge[i];
        int ar=find(a);
        int br=find(b);

        if(ar>br){
            uf[ar]=br;
            cnt++;
            ans+=c;
        }
        else if(ar<br){
            uf[br]=ar;
            cnt++;
            ans+=c;
        }
    }

    cout<<ans;
}
