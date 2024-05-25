#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    unordered_map<string,string> um;

    for(int i=0;i<n;i++){
        string s,e;
        cin>>s>>e;
        um[s]=e;
    }
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        cout<<um[s]<<"\n";
    }
}
