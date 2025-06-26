#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    int arr[100'001];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int s;
    cin>>s;

    bool v[100'001]={0,};
    stack<int> q;
    q.push(s);
    int cnt=1;
    v[s]=1;

    while(q.size()){
        int c=q.top();
        q.pop();
        for(int nt:{c+arr[c],c-arr[c]}){
            if(nt>=1&&nt<=n&&!v[nt]){
                q.push(nt);
                v[nt]=1;
                cnt++;
            }
        }
    }
    
    cout<<cnt;
}