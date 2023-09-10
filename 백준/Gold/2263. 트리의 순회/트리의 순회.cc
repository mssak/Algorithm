#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> inorder, postorder;
unordered_map<int, int> inorder_idx;

void find_preorder(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) {
        return;
    }

    // 포스트오더의 마지막 원소는 현재 서브트리의 루트
    int root = postorder[post_end];
    cout << root << " ";

    int root_idx_inorder = inorder_idx[root];  // 인오더에서의 루트 위치
    int left_size = root_idx_inorder - in_start;  // 왼쪽 서브트리의 크기

    // 왼쪽 서브트리 탐색
    find_preorder(in_start, root_idx_inorder-1, post_start, post_start+left_size-1);
    // 오른쪽 서브트리 탐색
    find_preorder(root_idx_inorder+1, in_end, post_start+left_size, post_end-1);
}

int main() {
    int n;
    cin >> n;

    inorder.resize(n);
    postorder.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    for (int i = 0; i < n; i++) {
        inorder_idx[inorder[i]] = i;
    }

    find_preorder(0, n-1, 0, n-1);
    return 0;
}
