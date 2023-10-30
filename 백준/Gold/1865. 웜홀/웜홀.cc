#include<bits/stdc++.h>
#define MAX 500
using namespace std;
using pii=pair<int,int>;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;

    while(T--){
        vector<pair<int,int>> edge[MAX];
        int N,M,W;
        cin>>N>>M>>W;
        
        for(int i=0;i<M;i++){
            int s,e,t;
            cin>>s>>e>>t;
            s--;e--;
            edge[s].push_back({e,t});
			edge[e].push_back({s,t});
        }
        for(int i=0;i<W;i++){
            int s,e,t;
            cin>>s>>e>>t;
            s--;e--;
            edge[s].push_back({e,-t});
        }

		int v[MAX];
		memset(v,0x3f,sizeof(v));
		v[0]=0;

		for(int i=0;i<N;i++){
			for(int s=0;s<N;s++){
				for(auto k:edge[s]){
					auto [e,t]=k;
					if(v[e]>v[s]+t){
						v[e]=v[s]+t;
					}
				}
			}
		}

		bool ans=false;
		for(int s=0;s<N;s++){
			if(ans){
				break;
			}
			for(auto k:edge[s]){
				auto [e,t]=k;
				if(v[e]>v[s]+t){
					ans=true;
					break;
				}
			}
		}

		if(ans){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
