#include<bits/stdc++.h>
#define MAX 100'000
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[MAX];

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int an,ans;
    sort(arr,arr+n);

    int i=0,j=n-1,m=INT_MAX;

    while(i<j){
        int s=arr[i]+arr[j];
        if(abs(s)<m){
            an=i;
            ans=j;
            m=abs(s);
        }

        if(s==0){
            break;
        }
        else if(s>0){
            j--;
        }
        else{
            i++;
        }
    }

    cout<<arr[an]<<" "<<arr[ans];
}