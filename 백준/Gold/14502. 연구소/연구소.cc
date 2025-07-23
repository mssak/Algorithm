#include<bits/stdc++.h>
#define MAX 8
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

	vector<pii> virus;
	vector<pii> empty;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]==0){
				empty.push_back({i,j});
			}else if(arr[i][j]==2){
				virus.push_back({i,j});
			}
		}
	}

	vector<int> per;
	for(int i=0;i<empty.size()-3;i++){
		per.push_back(0);
	}
	for(int i=0;i<3;i++){
		per.push_back(1);
	}

	int dy[4]={1,0,-1,0};
	int dx[4]={0,1,0,-1};

	int ans=0;
	do{
		vector<vector<int>> tmp(arr);
		for(int i=0;i<empty.size();i++){
			if(per[i]){
				auto[ty,tx]=empty[i];
				tmp[ty][tx]=1;
			}
		}
	
		int remain=empty.size()-3;
		
		queue<pii> q;
		for(auto[vy,vx]:virus){
			q.push({vy,vx});
		}

		while(q.size()){
			auto [cy,cx]=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int ny=cy+dy[i];
				int nx=cx+dx[i];
			
				if(ny>=0&&ny<n&&nx>=0&&nx<m&&tmp[ny][nx]==0){
					tmp[ny][nx]=2;
					q.push({ny,nx});
					remain--;
				}
			}
		}
		ans=max(ans,remain);
	}while(next_permutation(per.begin(),per.end()));

	cout<<ans;
}