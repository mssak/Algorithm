#include<iostream>
using namespace std;

int main(){
    int m,l,a,b;
    cin>>m;
    cin>>l;
    for(int i=0;i<l;i++){
        cin >> a >> b;
        m-=a*b;
    }
    
    if(m==0) cout << "Yes";
    else cout << "No";
}