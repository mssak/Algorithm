#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,cnt=0;
	string s;
	vector<string> se;
	set<string> ans;
    cin>>a>>b;

	while(a--){
		cin>>s;
		se.push_back(s);
	}

	sort(se.begin(),se.end());
	while(b--){
		cin>>s;
		if(binary_search(se.begin(),se.end(),s)){
			ans.insert(s);
		}
	}

	cout<<ans.size()<<"\n";
	for(auto i:ans){
		cout<<i<<"\n";
	}
}