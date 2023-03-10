#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int a;
    int arr[30]={};
    
    for(int i=0;i<30;i++){
        cin>>a;
        arr[a-1]=1;
    }
    for(int i=0;i<30;i++){
        if(arr[i]==0) cout << i+1 << "\n";
    }
}