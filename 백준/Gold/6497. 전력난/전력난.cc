#include<bits/stdc++.h>
#define MAX 200'000
using namespace std;
using iii=tuple<int,int,int>;

int uf[MAX];

int find(int a)
{
    if(uf[a]==a){
        return a;
    }
    else return uf[a]=find(uf[a]);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        int m,n,s{0};
        cin>>m>>n;
        if(m==0 && n==0){
            break;
        }

        for(int i=0;i<m;i++){
            uf[i]=i;
        }

        vector<iii> dist;
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            s+=z;
            dist.emplace_back(z,x,y);
        }

        sort(dist.begin(),dist.end());

        int c{0};
        for(auto i:dist){
            auto [d,x,y]=i;

            int xr=find(x);
            int yr=find(y);

            if(xr!=yr){
                c++;
                s-=d;
                uf[xr]=yr;
            }
            if(c==m-1){
                break;
            }
        }
        cout<<s<<"\n";
    }
}
