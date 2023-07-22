#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<bool> v={true};

    int n=1;
    for(int i=1;i<13;i++){
        for(int j=0;j<n;j++){
            v.push_back(false);
        }
        for(int j=0;j<n;j++){
            v.push_back(v[j]);
        }
        n*=3;
    }

    int a;
    while(cin>>a){
        for(int i=0;i<pow(3,a);i++){
            if(v[i]){
                cout<<"-";
            }
            else{
                cout<<" ";
            }
        }
        cout<<"\n";
    }
}