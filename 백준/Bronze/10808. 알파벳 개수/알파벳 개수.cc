#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	int arr['z'+1]={};
    string s;
    cin>>s;

	for(char c:s){
		arr[c]+=1;
	}

	for(int i='a';i<='z';i++){
		cout<<arr[i]<<" ";
	}
}