#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;

    for(int i=1;i<=a;i++){
        for(int j=0;j<a-i;j++){
            cout<<" ";
        }
        for(int j=0;j<i*2-1;j++){
            cout<<"*";
        }
        cout<<"\n";
    }

    for(int i=a-1;i>=1;i--){
        for(int j=0;j<a-i;j++){
            cout<<" ";
        }
        for(int j=0;j<i*2-1;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}