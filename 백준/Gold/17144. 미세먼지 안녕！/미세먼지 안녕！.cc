#include<bits/stdc++.h>
#define MAX 51
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,t;
    cin>>n>>m>>t;

	vector<vector<int>> arr(n,vector<int>(m));

	int cu=-1;
	int cd;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]==-1){
				if(cu==-1){
					cu=i;
				}else{
					cd=i;
				}
			}
		}
	}

	int dy[4]={0,-1,0,1};
	int dx[4]={1,0,-1,0};
	while(t--){
		//spread
		vector<vector<int>> tmp(n,vector<int>(m));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]>0){
					int spreadCnt=0;
					int tospread=arr[i][j]/5;
					for(int d=0;d<4;d++){
						int ny=i+dy[d];
						int nx=j+dx[d];
						if(ny>=0&&ny<n&&nx>=0&&nx<m&&arr[ny][nx]!=-1){
							tmp[ny][nx]+=tospread;
							spreadCnt++;
						}
					}
					tmp[i][j]+=arr[i][j]-spreadCnt*tospread;
				}
			}
		}
		tmp[cu][0]=-1;
		tmp[cd][0]=-1;
		arr=tmp;

		//up clean
		for(int y=cu-2;y>=0;y--){
			arr[y+1][0]=arr[y][0];
		}
		for(int x=1;x<m;x++){
			arr[0][x-1]=arr[0][x];
		}
		for(int y=1;y<=cu;y++){
			arr[y-1][m-1]=arr[y][m-1];
		}
		for(int x=m-2;x>0;x--){
			arr[cu][x+1]=arr[cu][x];
		}
		arr[cu][1]=0;

		//down clean
		for(int y=cd+2;y<n;y++){
			arr[y-1][0]=arr[y][0];
		}
		for(int x=1;x<m;x++){
			arr[n-1][x-1]=arr[n-1][x];
		}
		for(int y=n-2;y>=cd;y--){
			arr[y+1][m-1]=arr[y][m-1];
		}
		for(int x=m-2;x>0;x--){
			arr[cd][x+1]=arr[cd][x];
		}
		arr[cd][1]=0;
	}

	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!=-1){
				ans+=arr[i][j];
			}
		}
	}
	cout<<ans;
}