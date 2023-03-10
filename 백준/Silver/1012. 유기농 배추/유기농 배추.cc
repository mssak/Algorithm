#include<bits/stdc++.h>
#define MAX 50
using namespace std;

bool visited[MAX][MAX];
bool arr[MAX][MAX];
int a,b,c;

void dfs(int i,int j)
{
    if(!arr[i][j]){
        return;
    }
    visited[i][j]=1;
    if((i-1>=0 and !visited[i-1][j])){
        dfs(i-1,j);
    }
    if(j-1>=0 and !visited[i][j-1]){
        dfs(i,j-1);
    }
    if(i+1<a and !visited[i+1][j]){
        dfs(i+1,j);
    }
    if(j+1<b and !visited[i][j+1]){
        dfs(i,j+1);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;

        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                arr[i][j]=0;
                visited[i][j]=0;
            }
        }

        for(int i=0;i<c;i++){
            int left,right;
            cin>>left>>right;
            arr[left][right]=1;
        }

        int cnt=0;

        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(!visited[i][j] and arr[i][j]){
                    cnt++;
                    dfs(i,j);
                }
            }
        }

        cout<<cnt<<"\n";
    }
}