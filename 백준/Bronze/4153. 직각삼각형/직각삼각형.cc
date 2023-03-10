#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c;
    while(true){
		cin>>a>>b>>c;
		if(!a){
			return 0;
		}

		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(),v.end());

		if(v[2]*v[2]==v[1]*v[1]+v[0]*v[0]){
			cout<<"right"<<"\n";
		}
		else{
			cout<<"wrong"<<"\n";
		}
	}
}