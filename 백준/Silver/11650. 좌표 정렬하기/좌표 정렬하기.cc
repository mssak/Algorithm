#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c;
    cin>>a;

    vector<pair<int,int>> v;

    while(a--){
        cin>>b>>c;
        v.push_back(pair<int,int>(b,c));
    }

    sort(v.begin(),v.end());

    for(auto i:v){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}