#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer=0;
    int server=0;
    queue<pair<int,int>> q;
    
    for(int i=0;i<players.size();i++){
        if(q.size()){
            auto [t,c]=q.front();
            if(t==i){
                server-=c;
                q.pop();
            }
        }
        int need=players[i]/m;
        if(server<need){
            q.push({i+k,need-server});
            answer+=need-server;
            server=need;
        }
    }
    return answer;
}