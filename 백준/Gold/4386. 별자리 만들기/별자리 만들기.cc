#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int uf[MAX];

int find(int a)
{
    if(uf[a]==a){
        return a;
    }
    else return find(uf[a]);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    double pos[MAX][2];
    vector<tuple<double,int,int>> dist;

    for(int i=0;i<n;i++){
        cin>>pos[i][0]>>pos[i][1];
    }

    for(int i=0;i<n;i++){
        uf[i]=i;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            dist.emplace_back(pow(pow(pos[i][0]-pos[j][0],2)+pow(pos[i][1]-pos[j][1],2),0.5),i,j);
        }
    }
    
    sort(dist.begin(),dist.end());

    int cnt{0};
    double ans{0};
    for(int i=0;cnt!=n-1;i++){
        auto [d,a,b]=dist[i];
        int ar=find(a);
        int br=find(b);

        if(uf[ar]!=uf[br]){
            uf[ar]=br;
            ans+=d;
            cnt++;
        }
    }

    printf("%.2f",ans);
}
