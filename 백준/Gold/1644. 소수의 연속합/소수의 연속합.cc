#include<bits/stdc++.h>
#define MAX 4'000'001
using namespace std;

bool notPrime[MAX]{false};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }

    for(int i=2;i<=n;i++){
        if(notPrime[i]) continue;
        for(int j=2;j*i<=n;j++){
            notPrime[i*j]=true;
        }
    }

    vector<int> prime;

    for(int i=2;i<=n;i++){
        if(!notPrime[i]){
            prime.push_back(i);
        }
    }

    int l{0},h{0},sum{prime[0]},ans{0};

    while(l<=h && h<prime.size()){
        if(sum==n){
            ans++;
            sum+=prime[++h];            
            continue;
        }
        else if(sum<n){
            sum+=prime[++h];
            continue;
        }
        else if(sum>n){
            sum-=prime[l++];
            continue;
        }
    }
    cout<<ans;
}