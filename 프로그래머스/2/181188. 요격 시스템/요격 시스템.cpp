#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    // 미사일 구간을 오른쪽 끝(e) 기준으로 오름차순 정렬합니다.
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });
    
    int answer = 0;
    // 현재 요격 미사일이 발사된 좌표를 저장합니다.
    // 초기값은 매우 작은 값으로 설정합니다.
    double shot = -1e18;
    
    // 각 미사일 구간에 대해 현재 shot이 (s, e) 내부에 있는지 확인합니다.
    for (const auto &t : targets) {
        int s = t[0], e = t[1];
        // 현재 shot이 (s, e)에 포함되지 않는 경우 새로운 요격 미사일을 발사합니다.
        if (!(s < shot && shot < e)) {
            shot = e - 0.5; // 구간 내부를 만족하는 좌표로 설정합니다.
            answer++;
        }
    }
    return answer;
}
