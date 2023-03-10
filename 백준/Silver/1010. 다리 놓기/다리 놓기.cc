#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n,a,b,ans=1;
	cin>>n;
	while(n--){
		ans=1;
		cin>>b>>a;

		for(int i=0;i<b;i++){
			ans*=(a-i);
			ans/=(i+1);
		}


		cout<<ans<<"\n";
	}
}