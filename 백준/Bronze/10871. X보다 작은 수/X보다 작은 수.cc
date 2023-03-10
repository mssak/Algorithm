#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin>>a>>b;
    
    int arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    
    for(int i:arr){
        if(i<b) cout<<i<<" ";
    }
}