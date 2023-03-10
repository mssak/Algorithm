#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,a,b;
    cin>>n;
    vector<pair<int,int>> v;
    while(n--){
        cin>>a>>b;
        v.push_back({a,b});
    }

    int cnt;
    for(auto i:v){
        cnt=1;
        for(auto j:v){
            if(i.first<j.first and i.second<j.second){
                cnt++;
            }
        }
        cout<<cnt<<" ";
    }
}