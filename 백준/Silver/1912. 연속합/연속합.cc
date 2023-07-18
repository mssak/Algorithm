#include<bits/stdc++.h>

using namespace std;

int arr[100'001]={};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,m=INT_MIN,c=0;
    cin>>a;

    for(int i=0;i<a;i++){
        cin>>arr[i];
        if(c>0){
            c+=arr[i];
        }
        else{
            c=arr[i];
        }
        m=max(m,c);
    }
    cout<<m;
}