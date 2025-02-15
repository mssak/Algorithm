#include<bits/stdc++.h>
#define MAX 501
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[MAX*2]={0};
    int n,m;
    cin>>n>>m;

    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            while(a){
                if(a%10==9){
                    sum++;
                    arr[i]++;
                    arr[n+j]++;
                }
                a/=10;
            }
        }
    }

    sort(arr,arr+n+m,greater<>());
    cout<<sum-arr[0];
}
