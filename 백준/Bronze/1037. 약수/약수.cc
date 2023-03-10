#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,a;
	cin>>n;
	vector<int> v;
    while(n--){
		cin>>a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());

	cout<<v[0]* (*(v.end()-1));
}