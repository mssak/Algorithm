#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    short a[n][m];
    short b[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> b[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] + b[i][j]<<" ";
        }
        cout<<"\n";
    }
}