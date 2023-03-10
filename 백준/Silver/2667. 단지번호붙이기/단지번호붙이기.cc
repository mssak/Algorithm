#include<bits/stdc++.h>
#define MAX 25
using namespace std;

bool visited[MAX][MAX]={};
bool arr[MAX][MAX];
int a;
int l;
void dfs(int i,int j)
{
    if(!arr[i][j]){
        return;
    }
    visited[i][j]=1;
    l++;
    if((i-1>=0 and !visited[i-1][j])){
        dfs(i-1,j);
    }
    if(j-1>=0 and !visited[i][j-1]){
        dfs(i,j-1);
    }
    if(i+1<a and !visited[i+1][j]){
        dfs(i+1,j);
    }
    if(j+1<a and !visited[i][j+1]){
        dfs(i,j+1);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>a;

    string s;
    for(int i=0;i<a;i++){
        cin>>s;
        for(int j=0;j<a;j++){
            if(s[j]=='0'){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=1;
            }  
        }
    }

    int cnt=0;
    vector<int> len;

    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(!visited[i][j] and arr[i][j]){
                cnt++;
                l=0;
                dfs(i,j);
                len.push_back(l);
            }
        }
    }
    sort(len.begin(),len.end());

    cout<<cnt<<"\n";
    for(auto i:len){
        cout<<i<<"\n";
    }
}