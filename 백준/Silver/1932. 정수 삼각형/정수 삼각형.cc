#include<bits/stdc++.h>
#define MAX 500
using namespace std;

int f(int y,int x) 
{
    return (y-1)*y/2+x-1; //y번째줄 x번째 원소의 인덱스
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[MAX*(MAX+1)/2];
    int dp[MAX*(MAX+1)/2]={0};

    //입력
    int n;
    cin>>n;

    int m=n*(n+1)/2;
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }

    //계산
    dp[0]=arr[0];

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1){
                dp[f(i,j)]=dp[f(i-1,j)]+arr[f(i,j)];
            }
            else if(j==i){
                dp[f(i,j)]=dp[f(i-1,j-1)]+arr[f(i,j)];
            }
            else{
                dp[f(i,j)]=max(dp[f(i-1,j)],dp[f(i-1,j-1)])+arr[f(i,j)];
            }
        }
    }

    //출력
    cout<<*max_element(dp+f(n,1),dp+f(n,n)+1);
}