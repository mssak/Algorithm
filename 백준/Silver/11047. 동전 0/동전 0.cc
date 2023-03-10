#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,d,ans=0;
    vector<int> v;
    cin>>a>>d;

    while(a--){
        cin>>b;
        v.push_back(b);
    }

    for(int i=v.size()-1;i>=0;i--){
        int j=d/v[i];
        ans+=j;
        d-=v[i]*j;
    }
    cout<<ans;
}