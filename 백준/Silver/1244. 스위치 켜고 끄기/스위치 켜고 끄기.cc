#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[101];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        if(a==1){
            for(int j=b;j<=n;j+=b){
                arr[j]=!arr[j];
            }
        }
        if(a==2){
            arr[b]=!arr[b];
            for(int j=1;b+j<=n&&b-j>=1;j++){
                if(arr[j+b]!=arr[b-j]){
                    break;
                }
                arr[j+b]=!arr[j+b];
                arr[b-j]=!arr[b-j];
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
        if(i%20==0){
            cout<<"\n";
        }
    }  
}
