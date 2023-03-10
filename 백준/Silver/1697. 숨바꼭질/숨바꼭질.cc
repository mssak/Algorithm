#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;

int v[MAX]={};
int a,b;

int bfs()
{
    queue<int> q;
    int c=a;
    q.push(c);
    v[c]=1;
    while(true){
        c=q.front();
        q.pop();
        if(c==b){
            return v[c];
        }
        if(c-1>=0 and v[c-1]==0){
            q.push(c-1);
            v[c-1]=v[c]+1;
        }
        if(c+1<MAX and v[c+1]==0){
            q.push(c+1);
            v[c+1]=v[c]+1;
        }
        if(2*c<MAX and v[2*c]==0){
            q.push(c*2);
            v[c*2]=v[c]+1;
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>a>>b;

    cout<<bfs()-1;
}