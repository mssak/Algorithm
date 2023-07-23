#include<bits/stdc++.h>
#define MAX 10'000
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[MAX];
    int u[MAX];
    int d[MAX];
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        u[i]=1;
        d[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && u[i]<u[j]+1){
                u[i]=u[j]+1;
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j] && d[i]<d[j]+1){
                d[i]=d[j]+1;
            }
        }
    }

    int m=INT_MIN;
    for(int i=0;i<n;i++){
        m=max(d[i]+u[i],m);
    }

    cout<<m-1;
}