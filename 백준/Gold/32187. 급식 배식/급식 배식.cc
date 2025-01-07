#include <bits/stdc++.h>
using namespace std;

/*
   BOJ 32187: 급식 배식 실패

   - N가지 음식, M명의 학생
   - j번 학생이 같은 음식을 배식받았다면 (j+1)번 학생은 그 음식을 받을 수 없음
   - 학생별로 가능한 (음식 번호, 행복도) 쌍이 주어질 때,
     모든 학생 행복도 합의 최댓값을 구하기
*/

static const int MAXN = 100000;

// food[i] : (학생번호 j, 행복도 v) 쌍의 목록
vector<pair<int, long long>> food[MAXN+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; 
    cin >> N >> M;
    
    // 입력 받기
    // j번 학생에 대해 l_j, 그리고 2*l_j개의 (p_{j,k}, v_{j,k}) 쌍
    // 해당 정보를 food[p_{j,k}]에 (j, v_{j,k}) 형태로 저장
    for(int j = 1; j <= M; j++){
        int l; 
        cin >> l;
        while(l--){
            long long p, v;
            cin >> p >> v;
            food[p].push_back({j, v});
        }
    }

    long long answer = 0LL;
    
    // 음식별로 "연속 학생 배제" 최대합 구해서 모두 더하기
    for(int i = 1; i <= N; i++){
        if(food[i].empty()) continue;
        
        // 학생번호 기준 오름차순 정렬
        sort(food[i].begin(), food[i].end());

        int sz = (int)food[i].size();
        vector<long long> dp(sz+1, 0LL); 
        // dp[t] : food[i]의 첫 t개 (index: 1~t) 고려 시, 얻을 수 있는 최대 행복도
        // food[i][t-1]가 (j_t, v_t)

        // prev 인덱스 구하기
        // prev[t]: t번째 원소(1-based)와 "연속 학생"이 충돌하지 않는 가장 큰 인덱스
        vector<int> prevIdx(sz+1, 0);

        // 투 포인터로 구할 수 있음
        int r = 0; // food[i] 벡터의 1-based 인덱스 기준 포인터
        for(int t = 1; t <= sz; t++){
            // j_t
            int j_t = food[i][t-1].first;
            // r을 옮겨가며 food[i][r]의 j_r <= j_t - 2가 되도록 맞춤
            while(r+1 < t && food[i][r].first <= j_t - 2){
                r++;
            }
            prevIdx[t] = r;
        }

        for(int t = 1; t <= sz; t++){
            auto [j_t, v_t] = food[i][t-1];
            // 고르는 경우 vs 안 고르는 경우
            // 안 고르면 dp[t] = dp[t-1]
            // 고르면 dp[ prevIdx[t] ] + v_t
            long long notPick = dp[t-1];
            long long pick = dp[ prevIdx[t] ] + v_t; 
            dp[t] = max(notPick, pick);
        }

        answer += dp[sz];
    }

    cout << answer << "\n";
    return 0;
}
