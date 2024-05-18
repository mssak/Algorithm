#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin>>n>>s;

    ll ans=0;
    for(int i=0;i<n;i++){
        ll t=s[i]-'a'+1;
        for(int j=0;j<i;j++){
            t*=31;
            t%=1234567891;
        }
        ans+=t;
        ans%=1234567891;
    }
    cout<<ans;
}
