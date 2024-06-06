#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int ans[10];
    memset(ans,0,sizeof(ans));

    int n;
    cin>>n;
    int arr[10];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    for(int i=0;i<n;i++){
        int ix=0;
        while(ans[ix]){
            ix++;
            arr[i]++;
        }
        while(ix!=arr[i]){
            ix++;
            while(ans[ix]){
                ix++;
                arr[i]++;
            }
        }
        ans[ix]=i+1;
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
