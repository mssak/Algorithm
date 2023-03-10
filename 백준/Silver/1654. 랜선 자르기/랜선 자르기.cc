#include<bits/stdc++.h>

using namespace std;

unsigned int k,n;
vector<unsigned int> v;

unsigned int f(unsigned int a,unsigned int b)
{
    if(a>b){
        return b;
    }
    unsigned int m=(a+b)/2;
    unsigned int cal=0;

    for(unsigned int i:v){
        cal+=i/m;
    }

    if(cal<n){
        return f(a,m-1);
    }
    else if(cal>=n){
        return f(m+1,b);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>k>>n;
    unsigned int max=0;

    for(unsigned int i=0;i<k;i++){
        unsigned int a;
        cin>>a;
        if(max<a){
            max=a;
        }
        v.push_back(a);
    }

    cout<<f(1,max);
}