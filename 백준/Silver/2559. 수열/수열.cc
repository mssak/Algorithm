#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c,sum=0;
    cin>>a>>b;

	int v[a+1];
	for(int i=1;i<=a;i++){
		cin>>c;
		v[i]=v[i-1]+c;
	}

	int m = INT_MIN;
	for(int i=b;i<=a;i++){
		m=max(m,v[i]-v[i-b]);
	}
	cout<<m;
}