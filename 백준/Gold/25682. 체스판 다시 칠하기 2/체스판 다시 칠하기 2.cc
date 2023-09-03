#include<bits/stdc++.h>
#define MAX 2001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int b[MAX][MAX]{0};
    int n,m,k;
    cin>>n>>m>>k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
            char a;
            cin>>a;
			if ((i + j) % 2 == 0) {
				b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (a == 'B' ? 0 : 1);
			}
			else {
				b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (a == 'W' ? 0 : 1);
			}
		}
	}

    int s=k*k;
    int ans=1e9;
    for(int i=0;i<=n-k;i++){
        for(int j=0;j<=m-k;j++){
            int tmp=b[i+k][j+k]-b[i+k][j]-b[i][j+k]+b[i][j];
            ans=min(ans,tmp);
            ans=min(ans,s-tmp);
        }
    }

    cout<<ans;
}
