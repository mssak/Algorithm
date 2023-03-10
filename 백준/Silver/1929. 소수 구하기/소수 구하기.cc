#include<iostream>
#include<stdio.h>
#define MAX 1'000'000

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
    int a,b;
    cin>>a>>b;
    for(;a<=b;a++){
        if(!board[a]){
            cout<<a<<"\n";
        }
    }
}