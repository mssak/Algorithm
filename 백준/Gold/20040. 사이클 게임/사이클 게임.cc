#include<bits/stdc++.h>
#define MAX 500'000
using namespace std;

int uf[MAX];

int f(int a){
    if(a==uf[a]) return a;
    return f(uf[a]);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        uf[i]=i;
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        int ar=f(a);
        int br=f(b);

        if(ar==br){
            cout<<i+1;
            return 0;
        }           
        else{
            ar>br?uf[ar]=br:uf[br]=ar;
        }

    }
    cout<<0;
}
