#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
using dii=tuple<double,int,int>;

int uf[MAX];
double pos[MAX][2];
vector<dii> edge;

double getd(int i,int j) {
    return sqrt((pos[i][0] - pos[j][0]) * (pos[i][0] - pos[j][0]) + (pos[i][1] - pos[j][1]) * (pos[i][1] - pos[j][1]));
}

int f(int a) {
    if(uf[a] != a) {
        uf[a] = f(uf[a]);
    }
    return uf[a];
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,cnt{0};
    cin>>n>>m;

    for(int i=0;i<n;i++){
        uf[i]=i;
        cin>>pos[i][0]>>pos[i][1];
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        int ar=f(a);
        int br=f(b);

        if(ar!=br){
            uf[ar]=br;
            cnt++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            edge.emplace_back(getd(i,j),i,j);
        }
    }

    sort(edge.begin(),edge.end());

    double ans{0};
    for(auto &[d,a,b] : edge){
        int ar=f(a);
        int br=f(b);
        if(ar!=br){
            ans+=d;
            uf[ar]=br;
            cnt++;
        }
        if(cnt==n-1){
            break;
        }
    }

    printf("%.2f",ans);
}
