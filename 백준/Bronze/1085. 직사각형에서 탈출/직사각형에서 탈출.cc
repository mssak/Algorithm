#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x,y,w,h;
    cin>>x>>y>>w>>h;
    
    vector<int> v;
    v.push_back(x);
    v.push_back(w-x);
    v.push_back(y);
    v.push_back(h-y);
    
    sort(v.begin(),v.end());
    cout<<v[0];
}