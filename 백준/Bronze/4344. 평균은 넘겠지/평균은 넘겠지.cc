#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.precision(3);
    cout<<fixed;
    
    int a,b,*arr,average,count;
    cin>>a;
    
    for(int i=0;i<a;i++){
        cin>>b;
        arr = new int[b];
        
        average=0;
        for(int j=0;j<b;j++){
            cin>>arr[j];
            average+=arr[j];
        }
        average=average/b;
        
        count=0;
        for(int j=0;j<b;j++){
            if(arr[j]>average){
                count+=1;
            }
        }
        cout<<(float)count/(float)b*100<<"%\n";
        delete[] arr;
    }
}