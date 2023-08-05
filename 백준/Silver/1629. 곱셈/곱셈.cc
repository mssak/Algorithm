#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(int a,int b,int c)
{
    if(b==0){
        return 1;
    }
    int h=f(a,b/2,c);
    int ans=(h*h)%c;
    if(b%2==1){
        ans=(ans*a)%c;
    }
    return ans;
}

signed main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c;
    cin>>a>>b>>c;

    cout<<f(a,b,c);
}