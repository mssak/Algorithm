#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int ans[10]{0};

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<=k;j++){
            if(ans[j]){
                k++;
            }
        }
        ans[k]=i+1;
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
