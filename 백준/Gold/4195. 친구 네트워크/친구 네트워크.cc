#include<bits/stdc++.h>
#define MAX 200'000
using namespace std;

int uf[MAX];
int sz[MAX];

int f(int a){
    if(uf[a]!=a){
        uf[a]=f(uf[a]);
    }
    return uf[a];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin>>T;
    
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<MAX;i++){
            uf[i]=i;
            sz[i]=1;
        }
        unordered_map<string,int> um;
        
        for(int i=0;i<n;i++){
            
   
        string as,bs;
        cin>>as>>bs;
        if(um.find(as)==um.end()){
            um[as]=um.size();   
        }
        int ai=um[as];
        if(um.find(bs)==um.end()){
            um[bs]=um.size();   
        }
        int bi=um[bs];
        ai=f(ai);
        bi=f(bi);
        if(ai!=bi){
            uf[ai]=bi;
            sz[bi]+=sz[ai];
            cout<<sz[bi]<<"\n";
        }
        else{
            cout<<sz[bi]<<"\n";
        }
        }
    }
}