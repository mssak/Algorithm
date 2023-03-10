#include<bits/stdc++.h>

using namespace std;

int a;
vector<int> v;

int f(int x)
{
    if(v[x]!=-1){
        return v[x];
    }

    else if(x%6==0){
        v[x]=min(f(x/2),f(x/3))+1;
        return v[x];
    }
    else if(x%3==0){
        v[x]=min(f(x/3),f(x-1))+1;
        return v[x];
    }

    else if(x%2==0){
        v[x]=min(f(x/2),f(x-1))+1;
        return v[x];
    }
    
    else{
        v[x]=f(x-1)+1;
        return v[x];
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>a;
    v.resize(a+1,-1);
    v[1]=0;

    cout<<f(a);
}