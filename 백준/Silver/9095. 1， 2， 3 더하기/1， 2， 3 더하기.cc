#include<bits/stdc++.h>
#define MAX 
using namespace std;

int arr[11]{0};

int f(int n){
    if(arr[n]){
        return arr[n];
    }

    int ans=0;
    for(int i=1;i<=3;i++){
        ans+=f(n-i);
    }
    return arr[n]=ans;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;

    arr[1]=1;
    arr[2]=2;
    arr[3]=4;

    while(T--){
        int n;
        cin>>n;

        cout<<f(n)<<"\n";
    }
}
