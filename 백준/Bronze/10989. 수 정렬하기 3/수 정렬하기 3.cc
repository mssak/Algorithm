#include<iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    int b;
    cin>>a;

    int board[10001]={};

    for(int i=0;i<a;i++){
        cin>>b;
        board[b]++;
    }

    for(int i=1;i<10001;i++){
        for(int j=0;j<board[i];j++){
            cout<<i<<"\n";
        }
    }
}