#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;
	for(int i=a;i>0;i--){
		for(int j=0;j<i;j++){
			cout<<"*";
		}
		cout<<"\n";
	}
}