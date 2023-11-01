#include<bits/stdc++.h>
#define MAX 1'000'001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    bool chk[MAX]{0};
    int arr[MAX];
    int ans[MAX]{0};
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        chk[arr[i]]=true;
    }
    for(int i=0;i<n;i++){
        int c=arr[i];
        for(int j=c;j<MAX;j+=c){
            if(chk[j]){
                ans[c]++;
                ans[j]--;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[arr[i]]<<" ";
    }
}