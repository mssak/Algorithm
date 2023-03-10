#include<iostream>
#include<stdio.h>
#define MAX 10000

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

    int a,b,ans;
    cin>>a;
    while(a-->0){
        cin>>b;
        for(int i=b/2;i>1;i--){
            if(!board[i] and !board[b-i]){
                ans = i;
                break;
            }
        }
        cout<<ans<<" "<<b-ans<<"\n";
    }
}