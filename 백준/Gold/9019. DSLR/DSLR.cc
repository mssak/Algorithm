#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000;

int T, A, B;
char command[MAX];
int previous[MAX];

pair<int, char> operate(int num, char op) {
    switch(op) {
        case 'D': return { (2 * num) % MAX, 'D' };
        case 'S': return { (num == 0) ? 9999 : num - 1, 'S' };
        case 'L': return { (num % 1000) * 10 + num / 1000, 'L' };
        case 'R': return { (num % 10) * 1000 + num / 10, 'R' };
    }
    return { -1, '?' }; // Should never reach here
}

string bfs() {
    memset(command, -1, sizeof(command));
    memset(previous, -1, sizeof(previous));
    queue<int> q;
    q.push(A);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur == B) {
            string result = "";
            while(cur != A) {
                result += command[cur];
                cur = previous[cur];
            }
            reverse(result.begin(), result.end());
            return result;
        }

        for(char op: {'D', 'S', 'L', 'R'}) {
            pair<int, char> next = operate(cur, op);
            if(command[next.first] == -1) {
                q.push(next.first);
                command[next.first] = next.second;
                previous[next.first] = cur;
            }
        }
    }
    return ""; // Should never reach here
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> T;
    while(T--) {
        cin >> A >> B;
        cout << bfs() << "\n";
    }
    return 0;
}
