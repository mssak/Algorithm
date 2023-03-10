n = int(input())
board = [list(input()) for _ in range(n)]
ans = 1


def search():
    global ans
    for i in range(n):
        cnt = 1
        for j in range(n-1):
            if board[i][j+1] == board[i][j]:
                cnt += 1
                ans = max(cnt, ans)
            else:
                cnt = 1

    for i in range(n):
        cnt = 1
        for j in range(n-1):
            if board[j+1][i] == board[j][i]:
                cnt += 1
                ans = max(cnt, ans)
            else:
                cnt = 1


for i in range(n):
    for j in range(n-1):
        board[i][j+1], board[i][j] = board[i][j], board[i][j+1]
        search()
        board[i][j+1], board[i][j] = board[i][j], board[i][j+1]

for i in range(n-1):
    for j in range(n):
        board[i+1][j], board[i][j] = board[i][j], board[i+1][j]
        search()
        board[i+1][j], board[i][j] = board[i][j], board[i+1][j]

print(ans)
