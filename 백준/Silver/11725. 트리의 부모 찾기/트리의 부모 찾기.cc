#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    int ans[MAX]{0};
    vector<int> v[MAX];

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int c=q.front();
        q.pop();

        for(int i:v[c]){
            if(!ans[i]){
                q.push(i);
                ans[i]=c;
            }
        }
    }

    for(int i=2;i<=n;i++){
        cout<<ans[i]<<"\n";
    }
}
