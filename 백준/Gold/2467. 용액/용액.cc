#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    int arr[MAX];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int s=0;
    int e=N-1;
    int as,ae;
    int m=2e9;
    while(s<e){
        int r=arr[s]+arr[e];
        if(abs(r)<m){
            m=abs(r);
            as=s;
            ae=e;
        }
        if(r==0) break;
        else if(r<0) s+=1;
        else e-=1;
    }

    cout<<arr[as]<<" "<<arr[ae];
}
