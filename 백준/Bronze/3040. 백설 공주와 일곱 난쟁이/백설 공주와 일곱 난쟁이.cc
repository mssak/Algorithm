#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[9],mask[9]={0,0,1,1,1,1,1,1,1};
    int b;
    
    for(int i=0;i<9;i++){
        cin>>b;
        arr[i]=b;
    }

    do{
        int sum=0;
        for(int i=0;i<9;i++){
            sum+=arr[i]*mask[i];
        }
        if(sum==100){
            break;
        }
    }while(next_permutation(mask,mask+9));

    for(int i=0;i<9;i++){
        if(mask[i]){
            cout<<arr[i]<<"\n";
        }
    }
}