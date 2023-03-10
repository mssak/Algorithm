#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c,t=0,ans=0;
    vector<pair<int,int>> v;

    cin>>a;

    while(a--){
        cin>>b>>c;
        v.push_back({c,b});
    }
    
    sort(v.begin(),v.end());

    for(auto i:v){
        if(i.second>=t){
            ans++;
            t=i.first;
        }
    }

    cout<<ans;
}