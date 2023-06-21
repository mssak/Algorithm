#include<bits/stdc++.h>
int arr[101];

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;


    for(int i=1;i<=n;i++){
        arr[i]=i;
    }

    int a,b,tmp;
    while(m--){
        cin>>a>>b;
        tmp=arr[a];
        arr[a]=arr[b];
        arr[b]=tmp;
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}