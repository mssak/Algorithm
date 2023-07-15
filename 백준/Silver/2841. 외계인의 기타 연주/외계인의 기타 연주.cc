#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<int> arr[6];

    int n,p;
    cin>>n>>p;

    int ans=0;
    while(n--){
        int a,b;
        cin>>a>>b;
        a--;

        while(!arr[a].empty() and arr[a].top()>b){
            arr[a].pop();
            ans++;
        }
        if(arr[a].empty() or arr[a].top()!=b){
            arr[a].push(b);
            ans++;
        }
    }
    cout<<ans;
}