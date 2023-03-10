#include<bits/stdc++.h>

using namespace std;

int n,m;
bool chk[9]={};
int ans[9]={};

void f(int d)
{
    if(d==m){
        for(int i=0;i<m;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    else{
        for(int i=1;i<=n;i++){
            if(!chk[i]){
                ans[d]=i;
                chk[i]=true;
                f(d+1);
                chk[i]=false;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    cin>>n>>m;

    f(0);
}