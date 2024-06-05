#include <bits/stdc++.h>
#define MAX 
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr2[] = {1,2,3,4,5,6,7,8};
    int ing[50][9];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> ing[i][j];
        }
    }

    int ans = 0;
    do {
        int arr[9]={arr2[0],arr2[1],arr2[2],0,arr2[3],arr2[4],arr2[5],arr2[6],arr2[7]};
        int score = 0;
        int player = 0;
        for(int i = 0; i < n; i++) {
            int out = 0;
            bool base[4] = {0, 0, 0, 0};

            while(out != 3) {
                base[0] = 1;
                if(ing[i][arr[player]] == 0) {
                    out++;
                } else if(ing[i][arr[player]] == 1) {
                    for(int j = 3; j >= 0; j--) {
                        if(base[j]) {
                            base[j] = 0;
                            if(j + 1 >= 4) {
                                score++;
                            } else {
                                base[j + 1] = 1;
                            }
                        }
                    }
                } else if(ing[i][arr[player]] == 2) {
                    for(int j = 3; j >= 0; j--) {
                        if(base[j]) {
                            base[j] = 0;
                            if(j + 2 >= 4) {
                                score++;
                            } else {
                                base[j + 2] = 1;
                            }
                        }
                    }
                } else if(ing[i][arr[player]] == 3) {
                    for(int j = 3; j >= 0; j--) {
                        if(base[j]) {
                            base[j] = 0;
                            if(j + 3 >= 4) {
                                score++;
                            } else {
                                base[j + 3] = 1;
                            }
                        }
                    }
                } else if(ing[i][arr[player]] == 4) {
                    for(int j = 3; j >= 0; j--) {
                        if(base[j]) {
                            base[j] = 0;
                            if(j + 4 >= 4) {
                                score++;
                            } else {
                                base[j + 4] = 1;
                            }
                        }
                    }
                }

                player++;
                if(player == 9) {
                    player = 0;
                }
            }
        }
        ans = max(score, ans);
    } while(next_permutation(arr2,arr2+8));

    cout << ans;
}
