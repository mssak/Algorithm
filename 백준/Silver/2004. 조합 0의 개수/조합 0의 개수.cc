#include<bits/stdc++.h>

using namespace std;

int find(int a,int b)
{
	int ans=0;
	for(long long i=b;i<=a;i*=b){
		ans+=a/i;
	}
	return ans;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin>>a>>b;

	cout<<min(find(a,5)-find(a-b,5)-find(b,5),find(a,2)-find(a-b,2)-find(b,2));
}