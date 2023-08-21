#include <bits/stdc++.h>
#define INF 0x7FFFFFFF


using namespace std;

typedef struct {
	int v, w;
} edge;
struct comp {
	bool operator() (const edge &e1, const edge &e2) {
		return e1.w > e2.w;
	}
};
int n, m, t, s, g, h;
vector<vector<edge>> graph(2001);
vector<int> candi;
priority_queue<edge, vector<edge>, comp> pq;
int dist[2001];

void input() {
	cin >> n >> m >> t >> s >> g >> h;
	for (int i = 1; i <= n; i++) {
		graph[i].clear();
	}
	candi.clear();
	for (int i = 0; i < m; i++) {
		int a, b, d; cin >> a >> b >> d;
		graph[a].push_back((edge){b, d}); graph[b].push_back((edge){a, d});
	}
	for (int i = 0; i < t; i++) {
		int a; cin >> a;
		candi.push_back(a);
	}
}

void dijk(int start) {
	pq = priority_queue<edge, vector<edge>, comp>();
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[start] = 0;
	pq.push((edge){start, 0});
	while (!pq.empty()) {
		edge p = pq.top(); pq.pop();
		for (int i = 0; i < graph[p.v].size(); i++) {
			edge e = graph[p.v][i];
			if (dist[e.v] <= dist[p.v] + e.w) continue;
			dist[e.v] = dist[p.v] + e.w;
			pq.push((edge){e.v, dist[e.v]});
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); cin.sync_with_stdio(false); cout.sync_with_stdio(false);
	int test; cin >> test;
	while (test--) {
		input();

		vector<int> stog(t);
		vector<int> sum1(t); // s -> g -> h -> goal
		vector<int> sum2(t); // s -> h -> g -> goal

		dijk(s);
		int S_H = dist[h];
		int S_G = dist[g];
		for (int i = 0; i < t; i++) stog[i] = dist[candi[i]];

		dijk(g);
		int G_H = dist[h];
		for (int i = 0; i < t; i++) sum2[i] += dist[candi[i]];

		dijk(h);
		for (int i = 0; i < t; i++) sum1[i] += dist[candi[i]];

		for (int i = 0; i < t; i++) {
			sum2[i] += S_H + G_H;
			sum1[i] += S_G + G_H;
		}

		vector<int> ans;
		for (int i = 0; i < t; i++) {
			if (stog[i] == min(sum1[i], sum2[i])) {
				ans.push_back(candi[i]);
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}