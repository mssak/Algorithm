#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    v.reserve(1'000'000);
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i]<<"\n";
    }
}