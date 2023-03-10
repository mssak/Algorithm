#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;

    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            a/=i;
            cout<<i<<"\n";
            i--;
        }
    }
    if(a>1) cout<<a;
}