#include <iostream>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long ans = 0;
    long long r1sq = (long long)r1 * r1;
    long long r2sq = (long long)r2 * r2;
    
    // x 좌표가 음수인 경우를 대칭으로 처리하기 위해 x = 0부터 r2까지 계산 후,
    // x != 0인 경우 2배 해줍니다.
    for (int x = 0; x <= r2; x++) {
        long long xsq = (long long)x * x;
        // x좌표에 대해 y의 최댓값: x^2 + y^2 <= r2^2 이므로
        int U = (int)floor(sqrt((long double)r2sq - xsq));
        int L = 0;
        // x^2가 r1^2보다 작은 경우에만 y의 하한을 구합니다.
        if (xsq < r1sq) {
            L = (int)ceil(sqrt((long double)r1sq - xsq));
        }
        // 만약 상한보다 하한이 크다면 해당 x에 대해서는 만족하는 y가 없습니다.
        if (U < L) continue;
        
        long long count_x = 0;
        // y 좌표는 음수, 0, 양수로 대칭을 이룹니다.
        // 만약 하한이 0이라면 y = 0인 경우는 한 번만 세고, 나머지는 2배합니다.
        if (L == 0) count_x = 2LL * U + 1; 
        else count_x = 2LL * (U - L + 1);
        
        // x = 0인 경우는 한 번만 더하고, 그 외는 좌우 대칭이므로 2배합니다.
        if (x == 0)
            ans += count_x;
        else
            ans += 2 * count_x;
    }
    return ans;
}