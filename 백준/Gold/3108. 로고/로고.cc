#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle
{
    int x1, y1, x2, y2;
};

// 두 직사각형이 겹치거나 맞닿아있는지 확인
bool isConnected(const Rectangle &r1, const Rectangle &r2)
{
    // 한 직사각형이 다른 직사각형 안에 완전히 포함되어 있는 경우 체크
    bool r1ContainsR2 = (r1.x1 < r2.x1 && r1.y1 < r2.y1 &&
                         r1.x2 > r2.x2 && r1.y2 > r2.y2);
    bool r2ContainsR1 = (r2.x1 < r1.x1 && r2.y1 < r1.y1 &&
                         r2.x2 > r1.x2 && r2.y2 > r1.y2);

    // 완전히 포함되는 경우 연결되지 않은 것으로 판단
    if (r1ContainsR2 || r2ContainsR1)
        return false;

    // 한 직사각형이 다른 직사각형의 완전히 왼쪽이나 오른쪽에 있는 경우
    if (r1.x2 < r2.x1 || r2.x2 < r1.x1)
        return false;
    // 한 직사각형이 다른 직사각형의 완전히 위나 아래에 있는 경우
    if (r1.y2 < r2.y1 || r2.y2 < r1.y1)
        return false;

    return true;
}

// DFS로 연결된 직사각형 그룹 찾기
void dfs(vector<Rectangle> &rects, vector<bool> &visited, int current)
{
    visited[current] = true;

    for (int i = 0; i < rects.size(); i++)
    {
        if (!visited[i] && isConnected(rects[current], rects[i]))
        {
            dfs(rects, visited, i);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<Rectangle> rects(N);
    for (int i = 0; i < N; i++)
    {
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
    }

    // 연결된 직사각형 그룹의 개수 찾기
    vector<bool> visited(N, false);
    int groups = 0;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfs(rects, visited, i);
            groups++;
        }
    }

    // (0,0)이 어떤 직사각형과 연결되어 있는지 확인
    bool connectedToOrigin = false;
    Rectangle origin = {0, 0, 0, 0};
    for (const auto &rect : rects)
    {
        if (isConnected(origin, rect))
        {
            connectedToOrigin = true;
            break;
        }
    }

    int result = groups - 1;
    if (!connectedToOrigin && N > 0)
        result++;

    cout << result << endl;

    return 0;
}