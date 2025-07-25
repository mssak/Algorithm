#include<bits/stdc++.h>
#define MAX 101
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,r;
    cin>>n>>m>>r;

	int score[MAX];
	for(int i=0;i<n;i++){
		cin>>score[i];
	}

	int dist[MAX][MAX];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j]=1e9;
		}
	}
	for(int i=0;i<n;i++){
		dist[i][i]=0;
	}
	for(int i=0;i<r;i++){
		int a,b,c;
		cin>>a>>b>>c;

		dist[a-1][b-1]=dist[b-1][a-1]=c;
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}

	int ans=0;
	for(int i=0;i<n;i++){
		int tmp=0;
		for(int j=0;j<n;j++){
			if(dist[i][j]<=m){
				tmp+=score[j];
			}
		}
		ans=max(ans,tmp);
	}

	cout<<ans;
}