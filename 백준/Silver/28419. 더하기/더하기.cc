#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n;
    cin>>n;
    ll sm[2]={0,0};
    ll od=0;
    for(ll i=0;i<n;i++){
        ll tmp;
        cin>>tmp;
        sm[od]+=tmp;
        od^=1;
    }

    if(n==3 && sm[0]>sm[1]){
        cout<<-1;
    }else{
        sort(sm,sm+2);
        cout<<sm[1]-sm[0];
    }
}
