#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,ans;
	string c,d;
	map<string,vector<string>> m;

    cin>>a;
	while(a--){
		m.clear();
		ans=1;
		cin>>b;
		while(b--){
			cin>>c>>d;
			m[d].push_back(c);
		}
		for(auto i:m){
			ans*=i.second.size()+1;
		}
		cout<<ans-1<<"\n";
	}
}