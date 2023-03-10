#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,n;
    cin>>a>>b;

	for(int i=1;i<=min(a,b);i++){
		if(a%i==0 and b%i==0){
			n=i;
		}
	}

	cout<<n<<"\n"<<(a*b)/n;
}