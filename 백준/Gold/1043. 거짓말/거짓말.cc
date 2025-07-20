#include<bits/stdc++.h>
#define MAX 51
using namespace std;
using ll = long long;

int tn;
int n,m;
int uf[MAX];

int f(int a){
    if(uf[a]!=a){
        return uf[a]=f(uf[a]);
    }else{
        return a;
    }
}

void ad(int a,int b){
    uf[f(a)]=f(b);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<=n;i++){
        uf[i]=i;
    }

    cin>>tn;
    for(int i=0;i<tn;i++){
        int a;
        cin>>a;
        ad(0,a);
    }


    vector<int> party[MAX];
    for(int i=0;i<m;i++){
        int c;
        cin>>c;
        for(int j=0;j<c;j++){
            int tmp;
            cin>>tmp;
            party[i].push_back(tmp);
            if(j>=1){
                ad(party[i][j-1],tmp);
            }
        }
    }


    int ans=0;
    for(int i=0;i<m;i++){
        bool lie=true;
        for(auto tmp:party[i]){
            if(f(tmp)==f(0)){
                lie=false;
                break;
            }
        }
        if(lie){
            ans++;
        }
    }

    cout<<ans;
}