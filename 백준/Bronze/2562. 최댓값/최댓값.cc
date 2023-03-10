#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[9];
    for(int i=0;i<9;i++){
        cin>>arr[i];
    }
    
    int max = arr[0];
    int index = 0;
    for(int i=1;i<9;i++){
        if(arr[i]>max){
            max = arr[i];
            index = i;
        }
    }
    cout << max <<"\n"<<index+1;
}