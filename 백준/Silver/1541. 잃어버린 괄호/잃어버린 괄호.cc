#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    char a;
    int n=0,ans=0;
    bool foundminus=false;
    while(cin>>a){
        if(a=='-' || a=='+'){
            if(foundminus){
                ans-=n;
                n=0;
            }
            else{
                ans+=n;
                n=0;
                if(a=='-'){
                    foundminus=true;
                }
            }
        }
        else{
            n*=10;
            n+=a-'0';
        }
    }
    if(foundminus){
        ans-=n;
    }
    else{
        ans+=n;
    }

    cout<<ans;
}