#include<bits/stdc++.h>

using namespace std;

int arr[1001]={0,};

int f(int a)
{
    if(arr[a]!=0){
        return arr[a];
    }
    else{
        arr[a] = (f(a-1)+f(a-2))%10'007;
        return arr[a];
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    arr[1]=1;
    arr[2]=2;

    int a;
    cin>>a;
    cout<<f(a);
}