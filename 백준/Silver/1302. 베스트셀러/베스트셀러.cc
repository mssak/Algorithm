#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    map<string,int> m;
    int a;
    string s;
    cin>>a;

    while(a--){
        cin>>s;
        m[s]++;
    }

    a=-1;
    for(auto i:m){
        if(a<i.second){
            s=i.first;
            a=i.second;
        }
    }
    cout<<s;
}