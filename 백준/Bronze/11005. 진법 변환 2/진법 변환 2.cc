#include<bits/stdc++.h>

using namespace std;

void f(int n,int b)
{
    if(n==0) return;

    int c=n%b;
    f(n/b,b);

    if(c<10) cout<<c;
    else cout<<char('A'+(c-10));
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long n,b;

    cin>>n>>b;

    f(n,b);
}