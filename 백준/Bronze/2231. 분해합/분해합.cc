#include<bits/stdc++.h>

using namespace std;

int fun(int n){
    int result=n;
    for(;n>0;n/=10){
        result+=n%10;
    }
    return result;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;
    
    int l=0;
    for(int i=a;i>0;i/=10){
        l++;
    }

    for(int i=a-9*l;i<a;i++){
        if(fun(i)==a){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
}