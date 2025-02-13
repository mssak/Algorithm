#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=1;i<=n-1;i++){
        cout<<string(i,'*')<<string(2*(n-i),' ')<<string(i,'*')<<"\n";
    }
    cout<<string(n*2,'*')<<"\n";
    for(int i=n-1;i>=1;i--){
        cout<<string(i,'*')<<string(2*(n-i),' ')<<string(i,'*')<<"\n";
    }
}
