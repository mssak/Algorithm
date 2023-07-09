#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int a;
    cin>>a;
    while(a--){
        cin>>s;
        if(s.size()<=9 and s.size()>=6){
            cout<<"yes";
        }
        else{
            cout<<"no";
        }
        cout<<endl;
    }
}