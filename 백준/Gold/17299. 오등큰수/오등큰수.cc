#include<bits/stdc++.h>

using namespace std;
#define MAX 1'000'001
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,ans[MAX],arr[MAX],h[MAX]={};
    stack<int> s;
    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]=a;
        h[a]++;
    }

    for(int i=n-1;i>=0;i--){
        while(s.size()&&h[s.top()]<=h[arr[i]]){
            s.pop();
        }
        if(!s.size()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}