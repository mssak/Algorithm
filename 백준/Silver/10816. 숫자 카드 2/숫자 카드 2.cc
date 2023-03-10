#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c,d;
    cin>>a;
	vector<int> arr(20'000'001);

	while(a--){
		cin>>b;
		arr[b+10'000'000]++;
	}

	cin>>c;

	while(c--){
		cin>>d;
		cout<<arr[d+10'000'000]<<" ";
	}
}