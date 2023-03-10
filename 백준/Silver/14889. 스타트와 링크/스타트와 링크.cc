#include<bits/stdc++.h>

using namespace std;

int arr[20][20];
bool player[20]={};
int l[10],r[10];
int n,mn=INT_MAX;

void dfs(int lp,int ls,int b)
{
    if(lp==n/2){
        int rs=0;
        int rp=0;
        for(int i=0;i<n;i++){
            if(!player[i]){
                for(int j=0;j<rp;j++){
                    rs+=arr[r[j]][i];
                    rs+=arr[i][r[j]];
                }
                r[rp++]=i;
            }
        }
        int dif=abs(ls-rs);
        mn=min(mn,dif);
    }

    else{
        for(int i=b+1;i<n;i++){
            if(!player[i]){
                player[i]=true;

                int ns=ls;
                for(int j=0;j<lp;j++){
                    ns+=arr[l[j]][i];
                    ns+=arr[i][l[j]];
                }
                l[lp]=i;

                dfs(lp+1,ns,i);
                player[i]=false;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            arr[i][j]=a;
        }
    }

    dfs(0,0,-1);
    cout<<mn;
}