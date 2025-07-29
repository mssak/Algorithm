#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

	vector<vector<int>> arr(n,vector<int>(m));

	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1){
				cnt++;
			}
		}
	}

	int dy[4]={1,0,-1,0};
	int dx[4]={0,-1,0,1};
	int ans=0;
	queue<pii> q;
	q.push({0,0});
	arr[0][0]=2;

	while(cnt){
		ans++;

		//외부공기 2로 만들기
		while(q.size()){
			auto [y,x]=q.front();
			q.pop();

			for(int i=0;i<4;i++){
				int ny=y+dy[i];
				int nx=x+dx[i];

				if(ny>=0&&ny<n&&nx>=0&&nx<m){
					if(arr[ny][nx]==0){
						arr[ny][nx]=2;
						q.push({ny,nx});
					}
				}
			}
		}

		
		//2랑 접촉한 치즈들 제거
		vector<pii> dlt;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]==1){
					int ct=0;
					for(int d=0;d<4;d++){
						int ny=i+dy[d];
						int nx=j+dx[d];

						if(arr[ny][nx]==2){
							ct++;
						}
					}

					if(ct>=2){
						dlt.push_back({i,j});
					}
				}
			}
		}

		for(auto[i,j]:dlt){
			q.push({i,j});
			arr[i][j]=2;
			cnt--;
		}
	}

	cout<<ans;
}