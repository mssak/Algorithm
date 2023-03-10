#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	set<string> s;
    string a;
    cin>>a;
	for(int i=0;i<a.size();i++){
		for(int j=i;j<a.size();j++){
			s.insert(a.substr(i,j-i+1));
		}
	}
	cout<<s.size();
}