#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n;
	ll arr[MAX];
	ll sm[MAX];
	arr[0]=0;
	sm[0]=0;
    cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
		sm[i]=sm[i-1]+arr[i];
	}
	int k;
	cin>>k;

	ll ans=0;
	for(int i=1;i<=n;i++){
		auto it=upper_bound(sm+i,sm+n+1,k+sm[i-1]);
		ans+=n-(it-sm)+1;
	}

	cout<<ans;
}
