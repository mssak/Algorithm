#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin>>s;

    vector<string> v;

    for(int i=0;i<s.size();i++){
        v.emplace_back(string(s.begin()+i,s.end()));
    }

    sort(v.begin(),v.end());

    for(auto i:v){
        cout<<i<<"\n";
    }
}