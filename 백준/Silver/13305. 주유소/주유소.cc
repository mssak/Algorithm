#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,ans=0;
    vector<int> p,d;
    cin>>a;

    for(int i=0;i<a-1;i++){
        cin>>b;
        d.push_back(b);
    }
    
    for(int i=0;i<a;i++){
        cin>>b;
        p.push_back(b);
    }
    for(int i=0;i<a;){
        int nxt=i+1;
        while(p[nxt]>p[i]){
            nxt++;
        }

        for(int j=i;j<nxt;j++){
            ans+=d[j]*p[i];
        }
        i=nxt;
    }

    cout<<ans;
}