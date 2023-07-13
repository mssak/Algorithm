#include<bits/stdc++.h>

using namespace std;

#define MAX 100'001



int main()
{
    int arr[MAX]={};
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;

    for(int i=0;i<=a;i++){
        arr[i]=i;
    }

    for(int i=1;i<=a;i++){
        for(int j=0;j*j<=i;j++){
            arr[i]=min(arr[i-j*j]+1,arr[i]);
        }
    }
    cout<<arr[a];
}