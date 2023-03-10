#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,f,t;
    cin>>a;
    f=a/5;
    while(f>=0){
        if((a-5*f)%3==0){
            t=(a-5*f)/3;
            cout<<f+t<<"\n";
            exit(0);
        }
        f--;
    }
    cout<<-1;
}