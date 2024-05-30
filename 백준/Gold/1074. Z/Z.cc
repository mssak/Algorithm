#include<bits/stdc++.h>
#define MAX 32768
using namespace std;

int a=0;
int r,c;

void f(int n,int y,int x){
    if(n==1){
        cout<<a;
    }
    else{
        if(y<n/2 && x<n/2){
            f(n/2,y,x);
        }
        else if(y<n/2 && x>=n/2){
            a+=(n/2)*(n/2);
            f(n/2,y,x-n/2);
        }
        else if(y>=n/2 && x<n/2){
            a+=(n/2)*(n/2)*2;
            f(n/2,y-n/2,x);
        }
        else if(y>=n/2 && x>=n/2){
            a+=(n/2)*(n/2)*3;
            f(n/2,y-n/2,x-n/2);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n>>r>>c;
    f(pow(2,n),r,c);
}
