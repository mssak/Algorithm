#include<bits/stdc++.h>

#define nl '\n'
#define sp ' '

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    char a;
    vector<char> v;
    while(cin>>a){
        v.push_back(a);
    }

    sort(v.begin(),v.end(),greater<>());

    for(auto i:v){
        cout<<i;
    }
}