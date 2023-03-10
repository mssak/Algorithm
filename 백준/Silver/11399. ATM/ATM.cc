#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,ans=0;
    vector<int> v;
    cin>>a;

    while(a--){
        cin>>b;
        v.push_back(b);
    }
    sort(v.begin(),v.end());

    for(int i=1;i<=v.size();i++)
    ans=accumulate(v.begin(),v.begin()+i,ans);

    cout<<ans;
}