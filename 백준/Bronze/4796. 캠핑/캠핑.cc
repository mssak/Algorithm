#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int l,p,v,c=0,ans;

    while(++c){
        cin>>l>>p>>v;
        if(l==0 and p==0 and v==0){
            return 0;
        }

        ans = v/p*l+min(v%p,l);
        printf("Case %d: %d\n",c,ans);
    }
}