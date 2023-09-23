#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, a, b = 0;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "add") {
            cin >> a;
            int mask = 1;
            mask <<= a;
            b |= mask;
        } else if (s == "remove") {
            cin >> a;
            int mask = 1;
            mask <<= a;
            b &= ~mask;
        } else if (s == "check") {
            cin >> a;
            int mask = 1;
            mask <<= a;
            if (b & mask) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (s == "toggle") {
            cin >> a;
            int mask = 1;
            mask <<= a;
            b ^= mask;
        } else if (s == "all") {
            b = 0xffffffff;
        } else if (s == "empty") {
            b = 0;
        }
    }

    return 0;
}
