#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c=0;
    cin>>a>>b;
    b--;
    vector<int> v;
    for(int i=1;i<=a;i++){
        v.push_back(i);
    }

    cout<<"<";
    while(v.size()-1){
        c+=b;
        c%=v.size();
        cout<<v[c]<<", ";
        v.erase(v.begin()+c);
    }
    cout<<v[0]<<">";
}