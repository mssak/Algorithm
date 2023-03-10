#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,n,m=0;
    cin>>a>>b;
	vector<int> v;
	v.reserve(a);
	v.push_back(0);
	while(a--){
		cin>>n;
		m+=n;
		v.push_back(m);
	}

	int c,d;
	while(b--){
		cin>>c>>d;
		cout<<v[d]-v[c-1]<<"\n";
	}
}