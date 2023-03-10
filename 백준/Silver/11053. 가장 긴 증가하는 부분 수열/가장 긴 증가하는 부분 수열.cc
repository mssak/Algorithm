#include<bits/stdc++.h>
#define MAX 1'000
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,arr[MAX],chk[MAX];
    cin>>n;
    for(int i=0;i<n;i++){
        chk[i]=1;
    }

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }

    int ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                chk[i]=max(chk[i],chk[j]+1);
                ans=max(ans,chk[i]);
            }
        }
    }

    cout<<ans;
}