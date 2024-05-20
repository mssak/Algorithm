#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    vector<int> v;
    cin>>n;
    if(!n){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    int cut=((double)n/20*3)+0.5;
    
    double ans=0;
    for(int i=cut;i<n-cut;i++){
        ans+=v[i];
    }

    ans=(int)(ans/(n-cut*2)+0.5);
    cout<<ans;
}
