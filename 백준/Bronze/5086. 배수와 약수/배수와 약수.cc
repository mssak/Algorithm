#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    while(true){
		cin>>a>>b;
		if(a==b and a==0){
			return 0;
		}
		if((a/b)*b==a){
			cout<<"multiple"<<"\n";
		}
		else if((b/a)*a==b){
			cout<<"factor"<<"\n";
		}
		else{
			cout<<"neither"<<"\n";
		}
	}
}