#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 501


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin>>a>>b;

    int ans=1;
    while(1){
        if(b==a){
            cout<<ans;
            return 0;
        }else if(b<a){
            cout<<-1;
            return 0;
        }
        else if(b%10==1){
            b/=10;
            ans++;
        }else if(b%2==0){
            b/=2;
            ans++;
        }else{
            cout<<-1;
            return 0;
        }
    }
}