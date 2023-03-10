#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long a,b,c,r,before=0,ans=0;
    cin>>a>>b;

	long long v[b]={};

	for(long long i=0;i<a;i++){
		cin>>c;
		r=(before+c)%b;
		if(r==0){
			ans++;
		}
		ans+=v[r];
		v[r]++;
		before=r;
	}

	cout<<ans;
}