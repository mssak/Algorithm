#include<iostream>
#include<stdio.h>
#define MAX 10000

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool board[MAX+1] ={};          //false = prim
    for(int i=2;i<=MAX/2;i++){
        for(int j=2;j*i<=MAX;j++){
            board[j*i]=true;
        }
    }
    board[1]=true;

    int ans=0;
    int a,b;
    unsigned int min=-1;
    int sum=0;
    cin>>a>>b;
    for(;a<=b;a++){
        if(!board[a]){
            sum+=a;
            if(min>a){
                min = a;
            }
        }
    }

    if(sum){
        cout<<sum<<"\n"<<min;
    }
    else{
        cout<<-1;
    }
}