#include<bits/stdc++.h>

using namespace std;

int euclidean(int a,int b)
{
	int r=a%b;
	if(r==0){
		return b;
	}
	return euclidean(b,r);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,a,b,e;
    cin>>n>>a;

	while(--n){
		cin>>b;
		e=euclidean(a,b);
		cout<<a/e<<"/"<<b/e<<"\n";
	}
}