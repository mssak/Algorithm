#include<bits/stdc++.h>
#define MAX 1'000'001
using namespace std;
using ll=long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    ll arr[MAX];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }

    ll s=1;
    ll e=1'000'000'001;
    ll ans=0;
    while(s<e){
        ll md=(s+e)/2;
        ll cnt=0;
        for(int i=0;i<m;i++){
            cnt+=arr[i]/md;
        }
        if(cnt>=n){
            s=md+1;
            ans=md;
        }
        else{
            e=md;
        }
    }
    cout<<ans;
}
