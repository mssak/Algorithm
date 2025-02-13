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

    int k=1;
    for(int i=1;i>0;i+=k){
        cout<<string(i-1,' ')<<string(2*(n-i)+1,'*')<<"\n";
        if(i==n)k=-1;
    }
}
