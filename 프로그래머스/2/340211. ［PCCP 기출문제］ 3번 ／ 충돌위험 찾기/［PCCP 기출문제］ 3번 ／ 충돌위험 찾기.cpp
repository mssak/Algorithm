#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstring>

using namespace std;

const int OFFSET = 100; // 좌표 변환을 위한 상수

// (r, c)를 단일 정수로 변환하는 함수
int encode(int r, int c) {
    return (r - 1) * OFFSET + (c - 1);
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int n = points.size();   // 포인트 개수
    int x = routes.size();   // 로봇 대수
    int m = routes[0].size(); // 각 로봇의 경로 길이 (문제 조건상 동일)

    // 포인트 번호를 좌표로 매핑
    vector<pair<int, int>> pointPos(n);
    for (int i = 0; i < n; i++) {
        pointPos[i] = {points[i][0], points[i][1]};
    }

    // 로봇별 이동 경로 저장 (시간 t별 좌표)
    vector<vector<pair<int, int>>> robotPath(x);

    for (int i = 0; i < x; i++) {
        // 시작 위치
        int startP = routes[i][0];
        auto [r, c] = pointPos[startP - 1];
        robotPath[i].push_back({r, c});

        // 경로 이동 시뮬레이션
        for (int j = 0; j < m - 1; j++) {
            int curP = routes[i][j];
            int nxtP = routes[i][j + 1];
            auto [r1, c1] = pointPos[curP - 1];
            auto [r2, c2] = pointPos[nxtP - 1];

            // r 좌표 먼저 이동
            while (r1 < r2) { r1++; robotPath[i].push_back({r1, c1}); }
            while (r1 > r2) { r1--; robotPath[i].push_back({r1, c1}); }
            // c 좌표 이동
            while (c1 < c2) { c1++; robotPath[i].push_back({r1, c1}); }
            while (c1 > c2) { c1--; robotPath[i].push_back({r1, c1}); }
        }
    }

    // 가장 긴 이동 경로 찾기
    int maxTime = 0;
    for (int i = 0; i < x; i++) {
        maxTime = max(maxTime, (int)robotPath[i].size());
    }

    int answer = 0;
    // 시간별 로봇 위치 충돌 체크
    for (int t = 0; t < maxTime; t++) {
        unordered_map<int, int> freq; // 각 좌표에 몇 개의 로봇이 있는지 저장
        for (int i = 0; i < x; i++) {
            if (t < robotPath[i].size()) {
                auto [r, c] = robotPath[i][t];
                freq[encode(r, c)]++;
            }
        }
        // 충돌 발생 체크
        for (auto &[_, count] : freq) {
            if (count >= 2) answer++;
        }
    }

    return answer;
}
