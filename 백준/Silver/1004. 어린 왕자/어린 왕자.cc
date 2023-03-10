#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t,n,nx,ny,nr,ax,ay,bx,by,ans;
    cin>>t;
	
	while(t--){
		cin>>ax>>ay>>bx>>by;
		cin>>n;
		ans=0;
		while(n--){
			cin>>nx>>ny>>nr;
			if((((nx-ax)*(nx-ax)+(ny-ay)*(ny-ay))<(nr*nr)) != (((nx-bx)*(nx-bx)+(ny-by)*(ny-by))<(nr*nr))){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
}