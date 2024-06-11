#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int ma[100'001]{0};
	int mb[100'001]{0};
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ma[a]++;
	}
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		mb[a]++;
	}
	
	int ansA{1},maxA{0},ansB{1},maxB{0};
	for(int i=1;i<=3;i++){
		maxA+=ma[i];
		maxB+=mb[i];
	}
	
	for(int i=2;i<=99'997;i++){
		int cntA=ma[i];
		int cntB=mb[i];
		for(int j=1;j<=2;j++){
			cntA+=ma[i-j];
			cntA+=ma[i+j];
			cntB+=mb[i-j];
			cntB+=mb[i+j];
		}

		if(cntA>maxA){
			maxA=cntA;
			ansA=i;
		}
		if(cntB>maxB){
			maxB=cntB;
			ansB=i;
		}
	}
	
	cout<<ansA<<" "<<ansB<<"\n";
	if(ansA>ansB){
		cout<<"good";
	}
	else{
		cout<<"bad";
	}
	
	
	return 0;
}