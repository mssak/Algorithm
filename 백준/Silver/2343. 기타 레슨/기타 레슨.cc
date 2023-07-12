#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[100'000];
    int n,m;
    cin>>n>>m;

    int sum=0;
    int max=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        if(max<arr[i]){
            max=arr[i];
        }
    }

    int l=max;
    int r=sum;
    int size,ans;
    while(l<=r){
        size=(r+l)/2;
        int s=0;
        int c=1;
        for(int i=0;i<n;i++){
            s+=arr[i];
            if(s>size){
                s=arr[i];
                c++;
            }
        }
        if(c>m){
            l=size+1;
        }
        else if(c<=m){
            ans=size;
            r=size-1;
        }
    }
    cout<<ans;
}