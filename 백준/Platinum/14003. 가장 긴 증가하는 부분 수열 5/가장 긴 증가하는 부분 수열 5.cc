#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> LIS; // 실제 값들을 저장하는 LIS
    vector<int> idx; // LIS의 원소들의 원래 인덱스를 저장
    vector<int> prev(N, -1); // 각 원소의 이전 원소의 인덱스를 저장

    for(int i = 0; i < N; i++) {
        if(LIS.empty() || LIS.back() < arr[i]) {
            if(!LIS.empty()) prev[i] = idx.back();
            LIS.push_back(arr[i]);
            idx.push_back(i);
        } else {
            auto it = lower_bound(LIS.begin(), LIS.end(), arr[i]);
            int pos = distance(LIS.begin(), it);
            *it = arr[i];
            idx[pos] = i;
            if(pos > 0) prev[i] = idx[pos - 1];
        }
    }

    cout << LIS.size() << "\n";

    // 실제 LIS 추적
    int p = idx.back();
    vector<int> actual_LIS;
    while(p != -1) {
        actual_LIS.push_back(arr[p]);
        p = prev[p];
    }

    reverse(actual_LIS.begin(), actual_LIS.end());
    for(int val : actual_LIS) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
