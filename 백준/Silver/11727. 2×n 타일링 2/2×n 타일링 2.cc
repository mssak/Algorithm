#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    cin>>n;

    long long arr[1001];
    arr[1]=1;
    arr[2]=3;

    for(int i=3;i<=n;i++){
        arr[i]=(arr[i-1]+arr[i-2]*2)%10'007;
    }

    cout<<arr[n];
}
