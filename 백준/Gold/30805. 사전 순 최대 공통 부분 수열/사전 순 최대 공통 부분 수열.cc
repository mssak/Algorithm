#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;
using pii = pair<int,int>;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int m;
    cin>>m;
	vector<int> b(m);
	for(int i=0;i<m;i++){
		cin>>b[i];
	}

	vector<int> ans;
	auto as=a.begin();
	auto bs=b.begin();
	int i=100;
	while(i>0){
		auto tmpa=find(as,a.end(),i);
		auto tmpb=find(bs,b.end(),i);
		
		if(tmpa!=a.end()&&tmpb!=b.end()){
			ans.push_back(i);
			as=tmpa+1;
			bs=tmpb+1;
			continue;
		}
		i--;
	}

	cout<<ans.size()<<"\n";
	for(int i:ans){
		cout<<i<<" ";
	}
}