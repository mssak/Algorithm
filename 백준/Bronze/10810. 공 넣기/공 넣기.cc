#include<bits/stdc++.h>
int arr[100];

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    int i,j,k;
    while(m--){
        cin>>i>>j>>k;
        i--;j--;
        for(int a=i;a<=j;a++){
            arr[a]=k;
        }

    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}