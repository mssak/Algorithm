#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool board[100][100]={};
    int n,a,b;
    cin>>n;
    while(n-->0){
        cin>>a>>b;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                board[a+i][b+j]=1;
            }
        }
    }

    int sum=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(board[i][j]){
                sum++;
            }
        }
    }

    cout<<sum;
}