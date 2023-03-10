#include<bits/stdc++.h>

using namespace std;

bool chk[9]={};
int n,m;

void f(int a,int b)
{
    if(a==m){
        for(int i=1;i<=n;i++){
            if(chk[i]){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
        return;
    }

    else{
        for(int i=b+1;i<=n;i++){
            if(!chk[i]){
                chk[i]=true;
                f(a+1,i);
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

    f(0,0);
}