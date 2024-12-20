#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int r,c,k;
    cin>>r>>c>>k;

    if(r%2==1&&c%2==1){
        if(k==1){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<1;
    }
}
