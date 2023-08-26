#include <cstdio>

int main() {
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif // _WIN32
	long long int n;
	scanf("%lld", &n);
	
	printf("%lld\n3\n", (n - 2) * (n - 1) * n / 6);
	return 0;
}