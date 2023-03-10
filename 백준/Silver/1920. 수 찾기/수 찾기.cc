#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    int n;
    cin>>n;
    v.reserve(n);

    while(n--){
        int a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    cin>>n;

    while(n--){
        int a;
        cin>>a;
        cout<<(binary_search(v.begin(),v.end(),a)?1:0)<<"\n";
    }
}