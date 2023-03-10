#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c,d;
    cin>>a;
	vector<bool> arr(20'000'001);

	while(a--){
		cin>>b;
		arr[b+10'000'000]=1;
	}

	cin>>c;

	while(c--){
		cin>>d;
		if(arr[d+10'000'000]==1){
			cout<<1<<" ";
		}
		else{
			cout<<0<<" ";
		}
	}
}