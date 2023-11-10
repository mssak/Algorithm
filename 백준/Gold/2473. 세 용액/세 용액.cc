#include<bits/stdc++.h>
#define MAX 5000
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    long long arr[MAX];

    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }

    long long ans[3];
    long long mn=1e18;
    sort(arr,arr+n);
    for(long long i=0;i<n;i++){
        long long s=i+1;
        long long e=n-1;

        while(s<e){
            long long sm=arr[i]+arr[s]+arr[e];
            if(abs(sm)<mn){
                mn=abs(sm);
                ans[0]=arr[i];
                ans[1]=arr[s];
                ans[2]=arr[e];
            }
            if(sm<0){
                s++;
            }
            else{
                e--;
            }

        }
    }
    for(long long i=0;i<3;i++){
        cout<<ans[i]<<" ";
    }
}
