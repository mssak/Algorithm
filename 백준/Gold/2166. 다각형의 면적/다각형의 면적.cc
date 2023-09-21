#include<bits/stdc++.h>
#define MAX 10'000 
using namespace std;

long long x[MAX];
long long y[MAX];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    cin>>n;
    double ans{0};

    for(long long i=0;i<n;i++){
        cin>>x[i];
        cin>>y[i];
    }

    for(long long i=0;i<n-1;i++){
        ans+=x[i]*y[i+1];
        ans-=x[i+1]*y[i];
    }
    ans+=x[n-1]*y[0];
    ans-=x[0]*y[n-1];

    printf("%.1f",abs(ans)/2);
}
