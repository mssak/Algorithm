#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    int n,l,a,p=-1,ans=0;;
    cin>>n>>l;
    l--;

    while(n--){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    for(int a:v){
        if(p<a){
            ans++;
            p=a+l;
        }
    }

    cout<<ans;
}