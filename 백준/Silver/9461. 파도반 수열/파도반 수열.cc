#include<bits/stdc++.h>

using namespace std;
long long arr[100]={};

long long f(long long a)
{
    if(arr[a]){
        return arr[a];
    }
    else{
        arr[a]=f(a-1)+f(a-5);
        return arr[a];
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    arr[0]=1;
    arr[1]=1;
    arr[2]=1;
    arr[3]=2;
    arr[4]=2;


    long long t;
    cin>>t;

    while(t--){
        long long a;
        cin>>a;
        a--;
        cout<<f(a)<<'\n';
    }
}