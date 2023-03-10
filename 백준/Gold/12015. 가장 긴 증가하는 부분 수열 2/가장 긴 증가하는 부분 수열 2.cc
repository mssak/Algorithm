#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lis;
    lis.push_back(-1); // 초기값 설정

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num > lis.back()) {
            lis.push_back(num);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            *it = num;
        }
    }

    cout << lis.size() - 1 << '\n';

    return 0;
}
