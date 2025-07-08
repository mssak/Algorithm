#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // C++ 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> S(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> S[i];
    }

    // 투 포인터 및 변수 초기화
    int left = 0;
    int maxLength = 0;
    int fruitCount[10] = {0}; // 과일 종류는 1~9이므로 크기 10 배열로 충분
    int distinctFruits = 0;   // 현재 창문 안에 있는 과일 종류의 수

    // right 포인터를 0부터 N-1까지 이동
    for (int right = 0; right < N; ++right) {
        // 1. 창문 확장: right 포인터가 가리키는 과일을 창문에 추가
        int newFruit = S[right];
        if (fruitCount[newFruit] == 0) {
            // 처음 보는 과일이면 종류의 수를 1 증가
            distinctFruits++;
        }
        fruitCount[newFruit]++;

        // 2. 창문 축소: 과일 종류가 2개를 초과하면 조건을 만족할 때까지 left 포인터 이동
        while (distinctFruits > 2) {
            int oldFruit = S[left];
            fruitCount[oldFruit]--;
            if (fruitCount[oldFruit] == 0) {
                // 해당 과일이 창문에서 완전히 빠지면 종류의 수를 1 감소
                distinctFruits--;
            }
            left++;
        }

        // 3. 정답 갱신: 현재 유효한 창문의 길이로 최대 길이를 갱신
        maxLength = std::max(maxLength, right - left + 1);
    }

    std::cout << maxLength << std::endl;

    return 0;
}