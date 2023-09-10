#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;
int n;
int in[MAX];
int in_index[MAX];
int post[MAX];

void f(int s,int e,int p)
{
    if(s>e){
        return;
    }

    int ri=in_index[post[p]];
    cout<<in[ri]<<" ";

    f(s,ri-1,p-(e-ri+1));
    f(ri+1,e,p-1);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>in[i];
        in_index[in[i]]=i;
    }
    for(int i=0;i<n;i++){
        cin>>post[i];
    }

    f(0,n-1,n-1);
}