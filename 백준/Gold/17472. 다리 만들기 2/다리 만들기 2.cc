#include<bits/stdc++.h>
#define MAX 11
using namespace std;
using ii=pair<int,int>;
using iii=tuple<int,int,int>;

int mp[MAX][MAX]{0};
int uf[6];

int find(int a)
{
    if(uf[a]==a){
        return a;
    }
    else return uf[a]=find(uf[a]);
}

ii dir[4]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y,int s)
{
    if(mp[x][y]!=-1){
        return;
    }
    
    mp[x][y]=s+1;
    for(auto i:dir){
        dfs(x+i.first,y+i.second,s);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a;
            cin>>a;
            if(a){
                mp[i][j]=-1;
            }
            else{
                mp[i][j]=0;
            }
        }
    }

    int siz{0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==-1){
                dfs(i,j,siz);
                siz++;
            }
        }
    }
    //test
    // cout<<"\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<mp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    //test


    vector<iii> bridges;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int st=mp[i][j];
            if(st==0){
                continue;
            }
            for(int k=3;i+k<=n;k++){
                int ed=mp[i+k][j];
                if(ed==0 || st==ed){
                    continue;
                }
                bool can=true;
                for(int l=i+1;l<i+k;l++){
                    if(mp[l][j]){
                        can=false;
                        break;
                    }
                }

                if(can){
                    bridges.emplace_back(k-1,st,ed);
                }
            }

            for(int k=3;j+k<=m;k++){
                int ed=mp[i][j+k];
                if(ed==0 || st==ed){
                    continue;
                }
                bool can=true;
                for(int l=j+1;l<j+k;l++){
                    if(mp[i][l]){
                        can=false;
                        break;
                    }
                }

                if(can){
                    bridges.emplace_back(k-1,st,ed);
                }
            }
        }
    }
    sort(bridges.begin(),bridges.end());

    for(int i=0;i<siz;i++){
        uf[i]=i;
    }

    int ans{0};
    int cnt{0};
    for(auto i:bridges){
        auto [d,a,b]=i;
        int ar=find(a);
        int br=find(b);

        if(ar!=br){
            cnt++;
            ans+=d;
            uf[ar]=br;
        }
        if(cnt==siz-1){
            cout<<ans;
            return 0;
        }
    }

    cout<<-1;
}
