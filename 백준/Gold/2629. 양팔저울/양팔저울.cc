#include<bits/stdc++.h>
using namespace std;
#define MAX 40'001
bool dp[2][MAX]={false};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    int flag=0;
    dp[flag][0]=true;
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int j=0;j<MAX;j++){
            if(dp[flag][j]){
                dp[flag^1][j]=true;
                dp[flag^1][abs(j-a)]=true;
                if(j+a<MAX){
                    dp[flag^1][j+a]=true;
                }
            }
        }
        flag^=1;
    }

    int m;
    cin>>m;
    while(m--){
        int a;
        cin>>a;
        if(dp[flag][a]){
            cout<<"Y\n";
        }
        else{
            cout<<"N\n";
        }
    }
}