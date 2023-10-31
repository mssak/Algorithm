#include<bits/stdc++.h>
#define MAX 1'000'001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    int arr[MAX];
    int e=-1;
    for(int i=0;i<m;i++){
        cin>>arr[i];
        e=max(e,arr[i]);
    }

    int s=1;
    int ans=0;
    while(s<=e){
        int md=(s+e)/2;
        int cnt=0;
        for(int i=0;i<m;i++){
            cnt+=arr[i]/md;
        }
        if(cnt>=n){
            s=md+1;
            ans=md;
        }
        else{
            e=md-1;
        }
    }
    cout<<ans;
}
