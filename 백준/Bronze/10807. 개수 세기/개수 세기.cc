#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    int arr[201]={};
    
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b;
        arr[b+100]+=1;
    }
   
    cin>>b;
    cout<<arr[b+100];
}