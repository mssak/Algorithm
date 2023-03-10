#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,a,b,sum;
	string s;
	char c;

    cin>>s>>n;

	while(n--){
		cin>>c>>a>>b;
		sum=0;
		for(int i=a;i<=b;i++){
			if(c==s[i]){
				sum++;
			}
		}
		cout<<sum<<"\n";
	}
}