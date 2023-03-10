#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;

	if(ax==bx){
		cout<<cx<<" ";
	}
	else{
		if(bx==cx){
			cout<<ax<<" ";
		}
		else{
			cout<<bx<<" ";
		}
	}
	if(ay==by){
		cout<<cy;
	}
	else{
		if(by==cy){
			cout<<ay;
		}
		else{
			cout<<by;
		}
	}
}