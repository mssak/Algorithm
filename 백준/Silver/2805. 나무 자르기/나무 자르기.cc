#include<bits/stdc++.h>

using namespace std;
vector<long long> v;
long long a,b;

long long cal(long long m)
{
    long long res=0;
    for(long long i:v){
        long long dif=i-m;
        if(dif>0){
            res+=i-m;
        }
    }
    return res;
}

long long f(long long s,long long e)
{
    long long m=(s+e)/2;
    long long c=cal(m);
    if(s>e or c==b){
        return m;
    }
    else if(c<b){
        return f(s,m-1);
    }
    else if(c>b){
        return f(m+1,e);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>a>>b;

    long long mx=0;
    for(long long i=0;i<a;i++){
        long long tm;
        cin>>tm;
        if(mx<tm){
            mx=tm;
        }
        v.push_back(tm);
    }

    cout<<f(0,mx);
}