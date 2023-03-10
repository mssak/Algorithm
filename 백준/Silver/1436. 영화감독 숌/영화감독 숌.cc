#include<bits/stdc++.h>

using namespace std;

bool fun(int n)
{
    for(;n>0;n/=10){
        if(n%1000==666){
            return true;
        }
    }
    return false;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,cnt,ans;
    cin>>a;
    
    for(int i=0;a>0;i++){
        if(fun(i)){
            ans=i;
            a--;
        }
    }
    cout<<ans;
}