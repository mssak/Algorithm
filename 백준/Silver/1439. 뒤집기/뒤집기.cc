#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
	cin>>s;
	if(s.size()==1){
		cout<<0;
	}else{
		int ans=0;
		for(int i=1;i<s.size();i++){
			if(s[i-1]!=s[i]){
				ans++;
			}
		}
		cout<<(ans+1)/2;
	}
}