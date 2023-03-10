#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    int a,sum;
    for(int i=0;i<5;i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    cout<<accumulate(v.begin(),v.end(),0)/5<<"\n"<<v[2];
}