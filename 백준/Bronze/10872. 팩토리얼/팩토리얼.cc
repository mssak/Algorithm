#include<bits/stdc++.h>

using namespace std;

int fac(int n)
{
    if(n<2){
        return 1;
    }
    else{
        return n*fac(n-1);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;

    cout<<fac(a);
}