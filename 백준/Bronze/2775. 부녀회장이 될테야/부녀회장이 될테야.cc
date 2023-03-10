#include<iostream>
#define MAX 14

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,k,n;
    int arr[MAX+1][MAX] ={};
    for(int i=0;i<MAX+1;i++){
        for(int j=0;j<MAX;j++){
            if(i==0) arr[i][j] = j+1;
            else if(j==0) arr[i][j] = 1;
            else arr[i][j] = arr[i-1][j]+arr[i][j-1];
        }
    }
    cin>>a;
    while(a--){
        cin>>k>>n;
        cout<<arr[k][n-1]<<"\n";
    }
}