#include<bits/stdc++.h>

using namespace std;

#define MAX 100'001
int arr[MAX]={};

int f(int a)
{
    if(arr[a] or a==0){
        return arr[a];
    }

    else{
        int v=INT_MAX;
        for(int i=1;i*i<=a;i++){
            v=min(f(a-i*i),v);
        }
        arr[a]=v+1;
        return v+1;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;

    cout<<f(a);
}