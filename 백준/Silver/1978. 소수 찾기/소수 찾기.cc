#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool board[1001] ={};
    for(int i=2;i<=500;i++){
        for(int j=2;j*i<=1000;j++){
            board[j*i]=true;
        }
    }
    board[1]=true;

    int ans=0;
    int n,a;
    cin>>n;
    while(n-->0){
        cin>>a;
        if(board[a]==false){
            ans++;
        }
    }
    cout<<ans;
}