#include<iostream>
using namespace std;
#define MAX 10'000


int sum(int n){
    int s = 0;
    while(n!=0){
        s+=n%10;
        n/=10;
    }
    return s;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int j;
    int arr[MAX+1]={};

    for(int i=1;i<=MAX;i++){
        j = i;
        j=j+sum(j);            
        if(j<=MAX) arr[j]=1;        
    }

    for(int i=1;i<MAX+1;i++){
        if(arr[i]==0){
            cout << i <<"\n";
        }
    }
}