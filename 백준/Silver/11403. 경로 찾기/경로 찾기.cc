#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 101

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    int edge[MAX][MAX]={0,};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>edge[i][j];
        }
    }

    for(int s=0;s<n;s++){
        queue<int> q;

        int v[MAX]={0,};
        q.push(s);

        while(q.size()){
            int c=q.front();
            q.pop();

            for(int i=0;i<n;i++){
                if(edge[c][i] && !v[i]){
                    v[i]=1;
                    q.push(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
}