#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#define MAX 100
using namespace std;

int n;
pair<double, double> stars[MAX];
bool visited[MAX];

double getDistance(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double prim() {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    double result = 0;
    pq.push({0, 0});

    while(!pq.empty()) {
        double cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(visited[curr]) continue;

        visited[curr] = true;
        result += cost;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                double distance = getDistance(stars[curr], stars[i]);
                pq.push({distance, i});
            }
        }
    }
    return result;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> stars[i].first >> stars[i].second;
    }

    cout.precision(2);
    cout << fixed << prim() << endl;
    return 0;
}
