#include<bits/stdc++.h>
#define MAX 101
using namespace std;


int a,b;
int e[MAX]={};
int v[MAX]={};

int bfs()
{
    queue<int> q;
    v[1]=1;
    q.push(1);
    while(!q.empty()){
        int c=q.front();
        q.pop();
        if(v[100]!=0){
            return v[100]-1;
        }
        for(int i=1;i<=6;i++){
            if(c+i<=100 and v[e[c+i]]==0){
                v[e[c+i]]=v[c]+1;
                q.push(e[c+i]);
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>a>>b;

    for(int i=0;i<MAX;i++){
        e[i]=i;
    }

    for(int i=0;i<a+b;i++){
        int x,y;
        cin>>x>>y;
        e[x]=y;
    }

    cout<<bfs();
}