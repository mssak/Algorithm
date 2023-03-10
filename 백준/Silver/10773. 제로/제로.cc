#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,s=0;
    int arr[100'000];
    cin>>a;
    while(a--){
        cin>>b;
        if(b){
            arr[s++]=b;
        }
        else{
            s--;
        }
    }
    cout<<accumulate(arr,arr+s,0);
}