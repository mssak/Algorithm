#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c;
	vector<int> s;
	cin>>a>>b;

	for(int i=0;i<a;i++){
		cin>>c;
		s.push_back(c);
	}
	
	sort(s.begin(),s.end());
	
	while(b--){
		cin>>c;
		if(binary_search(s.begin(),s.end(),c)){
			a--;
		}
		else{
			a++;
		}
	}
	cout<<a;
}