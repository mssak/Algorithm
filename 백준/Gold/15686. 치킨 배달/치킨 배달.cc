#include<bits/stdc++.h>
#define MAX 51
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    int arr[MAX][MAX];
    vector<pair<int,int>> h;
    vector<pair<int,int>> c;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            if(a==1){
                h.push_back({i,j});
            }else if(a==2){
                c.push_back({i,j});
            }
            arr[i][j]=a;
        }
    }
    int cc=c.size();
    int hc=h.size();

    vector<vector<int>> dist(cc,vector<int>(hc)); //[c][h]

    for(int i=0;i<cc;i++){
        auto [cy,cx]=c[i];
        for(int j=0;j<hc;j++){
            auto [hy,hx]=h[j];
            dist[i][j]=abs(cy-hy)+abs(cx-hx);
        }
    }

    vector<int> per;
    for(int i=0;i<cc-m;i++){
        per.push_back(0);
    }
    for(int i=0;i<m;i++){
        per.push_back(1);
    }

    int ans=1e9;
    do{
        int tmp=0;
        for(int i=0;i<hc;i++){
            int mn=1e9;
            for(int j=0;j<cc;j++){
                if(per[j]){
                    mn=min(mn,dist[j][i]);
                }
            }
            tmp+=mn;
        }
        ans=min(ans,tmp);
    }while(next_permutation(per.begin(),per.end()));

    cout<<ans;
}