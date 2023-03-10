#include<iostream>
#include<stdio.h>
#define MAX 123'456*2

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool board[MAX+1] ={};          //false = prim
    for(int i=2;i*i<=MAX;i++){
        if(!board[i]){
            for(int j=2;j*i<=MAX;j++){
                board[j*i]=true;
            }
        }
    }
    board[1]=true;

    int ans=0;
    int a,sum;
    cin>>a;
    while(a!=0){
        sum=0;
        for(int i=a+1;i<=2*a;i++){
            if(!board[i]){
                sum++;
            }
        }
        cout<<sum<<"\n";
        cin>>a;
    }
}