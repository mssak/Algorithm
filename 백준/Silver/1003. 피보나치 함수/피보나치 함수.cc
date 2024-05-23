#include<bits/stdc++.h>
#define MAX 41
using namespace std;

int a[MAX][2];

int f(int n,int m) {
    if(a[n][m]!=-1){
        return a[n][m];
    }
    else {
        return a[n][m]= f(n-1,m) + f(n-2,m);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0;i<MAX;i++){
        a[i][0]=-1;
        a[i][1]=-1;
    }

    a[0][0]=1;
    a[0][1]=0;
    a[1][0]=0;
    a[1][1]=1;

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        cout<<f(n,0)<<" "<<f(n,1)<<"\n";
    }
}