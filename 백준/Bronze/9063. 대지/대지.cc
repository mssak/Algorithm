#include <cstdio>

int main() {
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif // _WIN32
	int n;
	scanf("%d", &n);

	int x, y, max_x = -10001, max_y = -10000, min_x = 10001, min_y = 10001;
	while (n--) {
		scanf("%d %d", &x, &y);
		if (x > max_x) max_x = x;
		if (y > max_y) max_y = y;
		if (x < min_x) min_x = x;
		if (y < min_y) min_y = y;
	}

	printf("%d\n", (max_x - min_x) * (max_y - min_y));
	return 0;
}