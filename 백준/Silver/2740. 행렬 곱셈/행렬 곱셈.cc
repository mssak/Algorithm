#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int ar[MAX][MAX];
int arr[MAX][MAX];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ar[i][j];
        }
    }

    int k;
    cin>>m>>k;

    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int a=0;
            for(int t=0;t<m;t++){
                a+=ar[i][t]*arr[t][j];
            }
            cout<<a<<" ";
        }
        cout<<"\n";
    }
}