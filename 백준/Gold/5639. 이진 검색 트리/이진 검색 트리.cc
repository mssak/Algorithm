#include<bits/stdc++.h>
#define MAX 10'000
using namespace std;

int n=0;
int pre[MAX];

void f(int s,int e)
{
    if(s>e){
        return;
    }
    int r=pre[s];
    int t=e+1;
    for(int i=s;i<=e;i++){
        if(pre[i]>r){
            t=i;
            break;
        }
    }

    f(s+1,t-1);
    f(t,e);
    cout<<r<<"\n";
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    while(cin>>a){
        pre[n]=a;
        n++;
    }

    f(0,n-1);
}