#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second!=b.second){
        return a.second<b.second;
    }
    else{
        return a.first<b.first;
    }
}

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

    sort(v.begin(),v.end(),compare);

    for(auto i:v){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}