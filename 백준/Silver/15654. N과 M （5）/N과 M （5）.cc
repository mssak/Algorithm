#include<bits/stdc++.h>
#define MAX 9
using namespace std;
using ll = long long;

int n,m;
int arr[MAX];
int tmp[MAX];
bool v[MAX]={0,};

void dfs(int idx,int cnt)
{   
    tmp[cnt++]=arr[idx];
    v[idx]=1;    
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<tmp[i]<<" ";
        }
        cout<<"\n";
        v[idx]=0;
        return;
    }

    for(int i=0;i<n;i++){
        if(!v[i]) dfs(i,cnt);
    }
    v[idx]=0;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    for(int i=0;i<n;i++){
        dfs(i,0);
    };
}