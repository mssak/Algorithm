#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    vector<int> v;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    int x;
    cin>>x;

    int ans=0;
    int low=0;
    int hi=n-1;
    while(low<hi){
        if(v[low]+v[hi]>x){
            hi--;
        }
        else if(v[low]+v[hi]<x){
            low++;
        }
        else{
            ans++;
            hi--;
            low++;
        }
    }
    cout<<ans;
}