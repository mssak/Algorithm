#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000;

int T, A, B;
char command[MAX];
int previous[MAX];

int operate(int num, char op) {
    switch(op) {
        case 'D': return (2 * num) % MAX;
        case 'S': return (num == 0) ? 9999 : num - 1;
        case 'L': return (num % 1000) * 10 + num / 1000;
        case 'R': return (num % 10) * 1000 + num / 10;
    }
    return -1; // Should never reach here
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
            int next = operate(cur, op);
            if(command[next] == -1) {
                q.push(next);
                command[next] = op;
                previous[next] = cur;
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
