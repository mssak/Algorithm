#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;

    
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    while(m--){
        int a,b;
        cin>>a>>b;
        auto lo = lower_bound(v.begin(),v.end(),a);
        auto hi = upper_bound(v.begin(),v.end(),b);

        cout<<hi-lo<<"\n";
    }
}
