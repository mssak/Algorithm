#include<bits/stdc++.h>
#define MAX 128
using namespace std;

int arr[MAX][MAX];
string s;

int check(int x,int y,int n)
{
    int c=0;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            c+=arr[i][j];
        }
    }

    if(c==n*n){
        return 1;
    }
    else if(c==0){
        return 0;
    }
    else{
        return -1;
    }
}

void f(int x,int y,int n)
{
    int r=check(x,y,n);
    if(r==0){
        s+='0';
    }
    else if(r==1){
        s+='1';
    }
    else{
        s+='(';
        f(x,y,n/2);
        f(x,y+n/2,n/2);
        f(x+n/2,y,n/2);
        f(x+n/2,y+n/2,n/2);
        s+=')';
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string k;
        cin>>k;
        for(int j=0;j<n;j++){
            arr[i][j]=k[j]-'0';
        }
    }

    f(0,0,n);

    cout<<s;
}