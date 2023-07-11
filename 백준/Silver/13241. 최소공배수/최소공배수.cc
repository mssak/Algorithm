#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll a,ll b)
{
    ll r=a%b;

    if(r==0){
        return b;
    }
    else{
        return f(b,r);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll a,b;
    cin>>a>>b;

    if(a<b){
        ll tmp=a;
        a=b;
        b=tmp;
    }

    cout<<a/f(a,b)*b;
}