#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
	int n;
	string s;
    cin>>a>>b;
	
	unordered_map<string,int> name;
	map<int,string> number;

	for(int i=0;i<a;i++){
		cin>>s;
		name[s]=i+1;
		number[i+1]=s;
	}

	while(b--){
		cin>>s;
		string::const_iterator it = s.begin();
		while (it != s.end() && isdigit(*it)) ++it;
		if (it != s.end())
		{
			cout<<name[s]<<"\n";
		}
		else
		{
			n = stoi(s);
			cout<<number[n]<<"\n";
		}
	}
}