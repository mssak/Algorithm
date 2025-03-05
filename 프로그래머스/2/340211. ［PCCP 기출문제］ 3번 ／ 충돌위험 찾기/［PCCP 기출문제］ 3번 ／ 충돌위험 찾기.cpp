#include <bits/stdc++.h>
using namespace std;

struct robot {
    int y, x;      // 현재 좌표
    int to = 0;    // 현재 목표 포인트 인덱스 (routes[i][to])
    bool done = false; // 운송 완료 여부
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int numR = routes.size();
    
    // routes의 포인트 번호를 0-indexed로 조정합니다.
    for (auto &route : routes) {
        for (auto &p : route) {
            p--;
        }
    }
    
    vector<robot> robots(numR);
    // 각 로봇은 주어진 경로의 첫번째 포인트에서 시작합니다.
    for (int i = 0; i < numR; i++) {
        robots[i].y = points[routes[i][0]][0];
        robots[i].x = points[routes[i][0]][1];
        robots[i].to = 0;
        robots[i].done = false;
    }
    
    // 시간 0에서 활성 로봇들 간 충돌 위험(동일 좌표에 2대 이상)이 있으면 카운트합니다.
    {
        map<pair<int,int>, int> posCount;
        for (int i = 0; i < numR; i++){
            if(robots[i].done) continue;
            posCount[{robots[i].y, robots[i].x}]++;
        }
        for (auto &entry : posCount){
            if(entry.second >= 2)
                answer += 1;
        }
    }
    
    // 시간 0에서 로봇들은 경로의 시작점에 있으므로, 이미 도착한 것으로 보고
    // (마지막이 아니라면) 다음 목표 포인트로 이동하도록 경로 포인터를 업데이트합니다.
    for (int i = 0; i < numR; i++){
        if(!robots[i].done){
            int curPoint = routes[i][robots[i].to];
            if(robots[i].y == points[curPoint][0] && robots[i].x == points[curPoint][1]){
                if(robots[i].to == (int)routes[i].size() - 1) {
                    robots[i].done = true;
                } else {
                    robots[i].to++;
                }
            }
        }
    }
    
    // 모든 로봇이 운송을 마칠 때까지 시뮬레이션합니다.
    while (true) {
        bool activeExists = false;
        for (int i = 0; i < numR; i++){
            if(!robots[i].done) { activeExists = true; break; }
        }
        if (!activeExists) break;
        
        // 모든 활성 로봇에 대해 다음 이동할 위치를 미리 계산합니다.
        vector<pair<int,int>> nextPositions(numR);
        for (int i = 0; i < numR; i++){
            if(robots[i].done) continue;
            int targetY = points[routes[i][robots[i].to]][0];
            int targetX = points[routes[i][robots[i].to]][1];
            int curY = robots[i].y, curX = robots[i].x;
            int nextY = curY, nextX = curX;
            // r 좌표 이동을 우선하여 목표 방향으로 1칸 이동합니다.
            if(curY != targetY) {
                nextY = curY + (curY < targetY ? 1 : -1);
            } else if(curX != targetX) {
                nextX = curX + (curX < targetX ? 1 : -1);
            }
            nextPositions[i] = {nextY, nextX};
        }
        
        // 모든 활성 로봇의 위치를 동시에 갱신합니다.
        for (int i = 0; i < numR; i++){
            if(robots[i].done) continue;
            robots[i].y = nextPositions[i].first;
            robots[i].x = nextPositions[i].second;
        }
        
        // 이번 시간 단계에 각 좌표에 2대 이상의 활성 로봇이 있다면 충돌 위험 1회를 카운트합니다.
        {
            map<pair<int,int>, int> posCount;
            for (int i = 0; i < numR; i++){
                if(robots[i].done) continue;
                posCount[{robots[i].y, robots[i].x}]++;
            }
            for (auto &entry : posCount){
                if(entry.second >= 2)
                    answer += 1;
            }
        }
        
        // 이동 후, 각 로봇이 현재 목표 포인트에 도착했다면 처리합니다.
        for (int i = 0; i < numR; i++){
            if(robots[i].done) continue;
            int targetY = points[routes[i][robots[i].to]][0];
            int targetX = points[routes[i][robots[i].to]][1];
            if(robots[i].y == targetY && robots[i].x == targetX){
                // 마지막 목표에 도착했다면 해당 로봇은 운송을 마치고, 이번 시간 단계의 충돌 위험에 포함됩니다.
                if(robots[i].to == (int)routes[i].size() - 1) {
                    robots[i].done = true;
                } else {
                    robots[i].to++;
                }
            }
        }
    }
    
    return answer;
}
