#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    string c;
    cin>>a;

    vector<tuple<int,int,string>> v;

    for(int i=0;i<a;i++){
        cin>>b>>c;
        v.push_back(tuple<int,int,string>(b,i,c));
    }
    sort(v.begin(),v.end());

    for(auto i:v){
        cout<<get<0>(i)<<" "<<get<2>(i)<<"\n";
    }
}