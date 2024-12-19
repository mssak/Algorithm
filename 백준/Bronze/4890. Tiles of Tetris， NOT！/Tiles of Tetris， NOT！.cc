#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(1){
        ll a,b;
        cin>>a>>b;
        if(b<a) swap(a,b);

        if(a==0&&b==0){
            return 0;
        }

        ll mi=1;
        for(ll i=1;i<=a;i++){
            if(a%i==0 && b%i==0){
                mi=i;
            }
        }

        cout<<b/mi*a/mi<<"\n";
    }
}
