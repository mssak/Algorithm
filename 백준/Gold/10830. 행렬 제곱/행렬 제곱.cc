#include<bits/stdc++.h>
#define MAX 
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vv;
typedef vector<ll> v;

ll n,B;
vv arr(5,v(5));

vv mul(vv a,vv b)
{
    vv r(5,v(5,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                r[i][j]+=a[i][k]*b[k][j];
            }
            r[i][j]%=1'000;
        }
    }
    return r;
}

vv f(vv a,ll b)
{
    if(b==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]%=1000;
            }
        }
        return a;
    }
    vv half=f(a,b/2);
    vv r=mul(half,half);
    if(b%2==1){
        r=mul(r,a);
    }
    return r;
}

void print(vv a)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>B;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    print(f(arr,B));
}