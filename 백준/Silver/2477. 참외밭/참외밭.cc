#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c;
    cin>>a;
	vector<pair<int,int>> v;
	for(int i=0;i<6;i++){
		cin>>b>>c;
		v.push_back({b,c});
	}

	int big=1,small=1;
	for(int i=0;i<6;i++){
		if(v[i-2<0?i-2+6:i-2].first==v[i].first){
			big*=(v[i].second+v[i-2<0?i-2+6:i-2].second);
			small*=(v[i-1<0?i-1+6:i-1].second);
		}
	}
	cout<<(big-small)*a;
}