#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,ans=1;
    cin>>a>>b;

	for(int i=0;i<b;i++){
		ans*=(a-i);
		ans%=10007;
		while(ans%(i+1)){
			ans+=10007;
		}
		ans/=(i+1);
	}
	cout<<ans;
}