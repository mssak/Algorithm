#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    // i개의 물건을 훔쳤을 때, (B 도둑의 흔적이 b일 경우)
    // A 도둑이 남긴 흔적의 최솟값을 담을 DP 테이블
    // 불가능한 상태는 -1로 표기
    vector<vector<int>> dp(info.size() + 1, vector<int>(m + 1, -1));

    // 아직 아무것도 훔치지 않았을 때(A, B 도둑의 흔적 모두 0)는 가능하므로 0으로 설정
    dp[0][0] = 0;
    for(int i=0;i<info.size();i++){
        for(int j=0;j<m;j++){
            if(dp[i][j]==-1){
                continue;
            }
            
            //b가 훔쳤을때
            int newB=j+info[i][1];
            if(newB<m){
                if(dp[i+1][newB]==-1||dp[i+1][newB]>dp[i][j]){
                    dp[i+1][newB]=dp[i][j];
                }
            }
            //a가 훔쳤을때
            int newA=dp[i][j]+info[i][0];
            if(newA<n){
                if(dp[i+1][j]==-1||dp[i+1][j]>newA){
                    dp[i+1][j]=newA;
                }
            }
        }
    }
    
    int answer=INT_MAX;
    for(int i=0;i<=m;i++){
        if(dp[info.size()][i]!=-1){
            answer=min(answer,dp[info.size()][i]);
        }
    }
    if(answer==INT_MAX){
        answer=-1;
    }
    
    return answer;
}
