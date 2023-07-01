#include<bits/stdc++.h>

using namespace std;

int main()
{
    int p,q,c=0;
    cin>>p>>q;
    
    for(int i=1;i<=p;i++){
        if(p%i==0){
            c++;
        }
        if(c==q){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
}