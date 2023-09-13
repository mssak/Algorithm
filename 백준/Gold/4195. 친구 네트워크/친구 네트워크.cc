#include<bits/stdc++.h>
#define MAX 200'000
using namespace std;

int f;
int uf[MAX];
int siz[MAX];

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

    int T;
    cin>>T;

    while(T--){
        cin>>f;
        for(int i=0;i<f*2;i++){
            uf[i]=i;
            siz[i]=1;
        }

        unordered_map<string,int> m;
        for(int i=0;i<f;i++){
            string a,b;
            cin>>a>>b;
            if(m.find(a)==m.end()){
                m[a]=m.size();
            }
            if(m.find(b)==m.end()){
                m[b]=m.size();
            }

            int ai=m[a];
            int bi=m[b];

            int ar=find(ai);
            int br=find(bi);

            if(ar!=br){
                uf[ar]=br;
                siz[br]+=siz[ar];
            }

            cout<<siz[br]<<"\n";
        }
    }
}
