#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    string s;
    cin>>a;

    for(int i=0;i<a;i++){
        cin>>b>>s;
        for(int j=0;j<s.size();j++){
            for(int k=0;k<b;k++){
                cout << s[j];
            }
        }
        cout<<"\n";
    }
}