#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> star(int n)
{
    vector<pair<int,int>> v;
    if(n==1){
        v.push_back({0,0});
        return v;
    }
    else{
        n/=3;
        for(auto i:star(n)){
            v.push_back({i.first,i.second});
            v.push_back({i.first,i.second+n});
            v.push_back({i.first,i.second+n*2});
            v.push_back({i.first+n,i.second});
            v.push_back({i.first+n,i.second+n*2});
            v.push_back({i.first+n*2,i.second});
            v.push_back({i.first+n*2,i.second+n});
            v.push_back({i.first+n*2,i.second+n*2});
        }
        return v;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;

    vector<vector<char>> v(a,vector<char>(a,' '));

    for(auto i:star(a)){
        v[i.first][i.second]='*';
    }

    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cout<<v[i][j];
        }
        cout<<"\n";
    }
}