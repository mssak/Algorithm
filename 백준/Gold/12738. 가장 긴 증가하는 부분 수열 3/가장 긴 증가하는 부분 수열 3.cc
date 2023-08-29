#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (v.empty() || v.back() < num) {
            v.push_back(num);
        }
        else {
            *lower_bound(v.begin(), v.end(), num) = num;
        }
    }
    cout << v.size();

}