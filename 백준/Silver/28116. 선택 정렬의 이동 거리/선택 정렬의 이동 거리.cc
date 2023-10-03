#include<bits/stdc++.h>
#define MAX 500'001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    pair<int,int> arr[MAX];
    int pos[MAX];

    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        arr[i]={a,0};
        pos[arr[i].first]=i;
    }

    for(int i=1;i<=n;i++){
        int ni=pos[i];
        int d=ni-i;
        arr[ni].second+=d;
        arr[i].second+=d;
        swap(pos[i],pos[arr[i].first]);
        swap(arr[i],arr[ni]);
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i].second<<" ";
    }
}