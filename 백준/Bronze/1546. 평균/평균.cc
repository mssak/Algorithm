#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,max;
    float sum=0;
    
    cin>>a;
    float arr[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    
    max = *max_element(arr,arr+a);
    sum = sum/max*100;
    
    cout.precision(3);
    cout<<fixed;
    cout<<sum/a;
}