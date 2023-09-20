#include<bits/stdc++.h>
#define MAX 10'001
using namespace std;

int node[MAX];
vector<int> edge[MAX];
int p[MAX];
int dp[MAX][2]{0};

void findParent(int a)
{
    for(int i:edge[a]){
        if(i!=p[a]){
            p[i]=a;
            findParent(i);
        }
    }
}

int f(int a, int b)
{
    if (a <= 0) {
        return 0;
    }
    if (dp[a][b] != -1) {
        return dp[a][b];
    }

    if (b == 0) {
        // 현재 마을을 '우수 마을'로 선택하지 않은 경우
        int res = 0;
        for (int i : edge[a]) {
            if (i == p[a]) {
                continue;
            }
            // 자식 마을을 '우수 마을'로 선택하지 않거나 선택하는 경우 중에서 최대 값을 선택
            res += max(f(i, 0), f(i, 1));
        }
        return dp[a][b] = res;
    } else if (b == 1) {
        // 현재 마을을 '우수 마을'로 선택한 경우
        int res = node[a];
        for (int i : edge[a]) {
            if (i == p[a]) {
                continue;
            }
            // 자식 마을은 '우수 마을'로 선택하지 않아야 함
            res += f(i, 0);
        }
        return dp[a][b] = res;
    }
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>node[i];
        dp[i][1]=-1;
        dp[i][0]=-1;
    }

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    p[1]=-1;
    findParent(1);

    cout<<max(f(1,0),f(1,1));
}
