#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    int n,m,a,sum;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    cout<<v[n-m];
}