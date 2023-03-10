#include<iostream>
#include<string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    int a;
    cin>>s;

    a='a';
    for(int i=a;i<a+26;i++){
        cout << (int)s.find(i) << " ";
    }
}