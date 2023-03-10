#include<bits/stdc++.h>

using namespace std;

int ans[9]={};
int n,m;

void f(int a)
{
    if(a==m){
        for(int i=0;i<a;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    else{
        for(int i=1;i<=n;i++){
            ans[a]=i;
            f(a+1);
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