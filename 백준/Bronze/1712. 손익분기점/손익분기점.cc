#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int a,b,c,d=0;
    cin>>a>>b>>c;
    if((c-b)<=0) cout<<-1;
    else cout<< a/(c-b)+1;
}
