#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    cin.tie(NULL);

    int n,a,b,c;
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        printf("%d%02d\n",(c-1)%a+1,(c-1)/a+1);
    }
}