#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long n, m;
	cin >> n >> m;

	unordered_set<string> us;
	string s;

	for (long long ni = 0; ni < n; ni++) {
		cin >> s;
		us.insert(s);
	}

	long long result = 0;
	for (long long mi = 0; mi < m; mi++) {
		cin >> s;
		if (us.find(s) != us.end()) {
			result++;
		}
	}

	cout << result;

}