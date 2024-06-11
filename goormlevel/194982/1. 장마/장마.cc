#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;
	int arr[1001];

	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	unordered_set<int> us;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		
		for(int j=a;j<=b;j++){
			us.insert(j);
			arr[j]++;
		}
		
		if(i%3==0){
			while(us.size()){
				auto it=us.begin();
				arr[*it]--;
				it=us.erase(it);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
}
