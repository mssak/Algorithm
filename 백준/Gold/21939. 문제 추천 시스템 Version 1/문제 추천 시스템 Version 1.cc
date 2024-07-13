#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<int,int> um;
    set<pair<int,int>> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        s.insert({b,a});
        um[a]=b;
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        string cmd;
        cin>>cmd;
        if(cmd=="recommend"){
            int a;
            cin>>a;
            if(a==1){
                cout<<(*--s.end()).second<<"\n";
            }
            else{
                cout<<(*s.begin()).second<<"\n";
            }

        }else if(cmd=="add"){
            int a,b;
            cin>>a>>b;
            s.insert({b,a});
            um[a]=b;
        }
        else if(cmd=="solved"){
            int a;
            cin>>a;
            s.erase({um[a],a});
            um.erase(a);
        }
    }
}