#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	int r=a%b;
	if(r==0){
		return b;
	}
	else{
		return gcd(b,r);
	}
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,n;
    cin>>n;

	while(n--){
		cin>>a>>b;
		cout<<a*b/gcd(max(a,b),min(a,b))<<"\n";
	}
}