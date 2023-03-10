#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    set<string,greater<string>> s;
    int a;
    string sa,sb;
    cin>>a;

    while(a--){
        cin>>sa>>sb;
        if(sb=="enter"){
            s.insert(sa);
        }
        else{
            s.erase(sa);
        }
    }

    for(auto i:s){
        cout<<i<<"\n";
    }
}