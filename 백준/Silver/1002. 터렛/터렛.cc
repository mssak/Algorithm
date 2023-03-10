#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,ax,ay,bx,by,ar,br;
	cin>>n;
    while(n--){
		cin>>ax>>ay>>ar>>bx>>by>>br;

		double distance = sqrt(pow(ax-bx,2)+pow(ay-by,2));

		if(ax==bx and ay==by and ar==br){
			cout<<-1<<"\n";
		}
		else if(distance+min(ar,br)<max(ar,br)){
			cout<<0<<"\n";
		}
		else if(distance+min(ar,br)==max(ar,br)){
			cout<<1<<"\n";
		}
		else if(ar+br<distance){
			cout<<0<<"\n";
		}
		else if(ar+br>distance){
			cout<<2<<"\n";
		}
		else if(ar+br==distance){
			cout<<1<<"\n";
		}
	}
}