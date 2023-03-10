#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
	int a;
    for(int i=0;i<3;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	cout<<v[1];
}