#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;
    
    int arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    
    cout << *min_element(arr,arr+a)<<" ";
    cout << *max_element(arr,arr+a);
}