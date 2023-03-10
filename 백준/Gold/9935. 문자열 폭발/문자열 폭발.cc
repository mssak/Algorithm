#include<bits/stdc++.h>

using namespace std;

bool boom(vector<char> &v,string b)
{
    int vsiz=v.size();
    int bsiz=b.size();
    if(vsiz<bsiz){
        return false;
    }
    else{
        for(int i=1;i<=bsiz;i++){
            if(v[vsiz-i]!=b[bsiz-i]){
                break;
            }
            else if(i==bsiz){
                for(int j=0;j<bsiz;j++){
                    v.pop_back();
                }
                return true;
            }
        }
        return false;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s,b;
    cin>>s>>b;
    vector<char> v;
    for(auto c:s){
        v.push_back(c);
        while(boom(v,b));
    }

    if(v.size()){
        for(auto c:v){
            cout<<c;
        }
    }
    else{
        cout<<"FRULA";
    }
}