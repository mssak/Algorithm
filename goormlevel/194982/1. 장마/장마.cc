#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;
	int house[1001];

	for(int i=1;i<=n;i++){
		cin>>house[i];
	}
	
	bool rained[1001]{0};
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		
		for(int j=a;j<=b;j++){
			rained[j]=1;
			house[j]++;
		}
		
		if(i%3==0){
			for(int j=1;j<=n;j++){
				if(rained[j]){
					house[j]--;
					rained[j]=0;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<house[i]<<" ";
	}
}
