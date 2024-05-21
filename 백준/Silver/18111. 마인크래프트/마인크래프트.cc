#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> land(n, vector<int>(m));
    int min_height = 256, max_height = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> land[i][j];
            min_height = min(min_height, land[i][j]);
            max_height = max(max_height, land[i][j]);
        }
    }

    int optimal_time = INT_MAX;
    int optimal_height = -1;

    for (int height = min_height; height <= max_height; ++height) {
        int time = 0;
        int blocks = b;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int diff = land[i][j] - height;
                if (diff > 0) {
                    time += diff * 2; // Removing blocks takes 2 seconds each
                    blocks += diff;
                } else if (diff < 0) {
                    time += -diff; // Adding blocks takes 1 second each
                    blocks += diff; // diff is negative, so we subtract from blocks
                }
            }
        }

        if (blocks >= 0) {
            if (time < optimal_time || (time == optimal_time && height > optimal_height)) {
                optimal_time = time;
                optimal_height = height;
            }
        }
    }

    cout << optimal_time << " " << optimal_height << "\n";
    return 0;
}
