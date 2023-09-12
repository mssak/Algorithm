#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent; // 각 노드의 부모 노드 정보를 저장하는 배열
    vector<int> rank;   // 트리의 높이를 저장하는 배열

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return; // 이미 같은 집합

        // 랭크가 높은 트리에 낮은 트리를 합침
        if (rank[u] > rank[v]) swap(u, v);

        parent[u] = v;
        if (rank[u] == rank[v]) rank[v]++;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, c, a, b;
    cin >> N >> M;

    UnionFind uf(N);

    for (int i = 0; i < M; i++) {
        cin >> c >> a >> b;
        if (c == 0) {
            uf.merge(a, b);
        } else {
            if (uf.find(a) == uf.find(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
