#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c;
    cin>>a>>b>>c;
    c-=a;
    if(c%(a-b)) cout << c/(a-b)+2;
    else cout << c/(a-b)+1;
}