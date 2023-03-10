#include<bits/stdc++.h>

using ll = long long;
using namespace std;

ll n,k;

ll f(ll m)
{
    ll sum=0;
    for(ll i=1;i<=n;i++){
        sum+=min(m/i,n);
    }
    return sum;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;

    ll s=1,e=n*n,m,r;

    while(s<=e){
        m=(e+s)/2;
        r=f(m);
        if(r>=k){
            e=m-1;
        }
        else if(r<k){
            s=m+1;
        }
    }

    cout<<s;
}