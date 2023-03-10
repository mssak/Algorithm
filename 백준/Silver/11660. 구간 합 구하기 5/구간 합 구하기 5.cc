#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c,before=0;
    cin>>a>>b;

	vector<int> v;
	v.push_back(0);
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			cin>>c;
			v.push_back(before+c);
			before+=c;
		}
	}
	
	int ax,ay,bx,by,sum;
	while(b--){
		cin>>ay>>ax>>by>>bx;
		ax--;ay--;bx--;by--;
		
		sum=0;
		for(int i=ay;i<=by;i++){
			sum+=v[i*a+bx+1]-v[i*a+ax];
		}
		cout<<sum<<"\n";
	}
}