#include<bits/stdc++.h>
#define MAX 102
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int map[MAX][MAX][4];
    int w,h;
    vector<pair<int,int>> v;
    cin>>h>>w;

    for(int i=0;i<w+2;i++){
        for(int j=0;j<h+2;j++){
            for(int k=0;k<4;k++){
                map[i][j][k]=-1;
            }
        }
    }

    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            char c;
            cin>>c;
            int t;
            if(c=='.'){
                t=1e9;
            }
            else if(c=='C'){
                v.push_back({i,j});
                t=1e9;
            }
            else if(c=='*'){
                t=-1;
            }
            
            for(int k=0;k<4;k++){
                map[i][j][k]=t;
            }
        }
    }

    queue<tuple<int,int,int,int>> q;
    q.push({v[0].first,v[0].second,0,0});
    q.push({v[0].first,v[0].second,0,1});
    q.push({v[0].first,v[0].second,0,2});
    q.push({v[0].first,v[0].second,0,3});

    int dir[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
    while(q.size()){
        auto[ci,cj,cc,cd]=q.front();
        q.pop();
        if(map[ci][cj][cd]==-1){
            continue;
        }
        if(map[ci][cj][cd]>cc){
            map[ci][cj][cd]=cc;
            for(int i=0;i<4;i++){
                int ni=ci+dir[i][0];
                int nj=cj+dir[i][1];
                int nc=cc;
                if(i!=cd){
                    nc++;
                }
                q.push({ni,nj,nc,i});
            }
        }
    }

    cout<<*min_element(map[v[1].first][v[1].second],map[v[1].first][v[1].second]+4);
}
