#include<bits/stdc++.h>
int arr[101],tmp[101];

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

    int a,b;
    while(m--){
        cin>>a>>b;
        for(int i=a;i<=b;i++){
            tmp[i]=arr[i];
        }
        for(int i=a;i<=b;i++){
            arr[i]=tmp[b-(i-a)];
        }
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}