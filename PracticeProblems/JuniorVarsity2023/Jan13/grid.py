from collections import deque


n, m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, input())))
q = deque([(0, 0)])
visited = [[False] * m for _ in range(n)]
visited[0][0] = True
res = 1
while q:
    for _ in range(len(q)):
        row, col = q.popleft()
        k = arr[row][col]
        # print(row, col, k)
        for dr, dc in [(-k, 0), (k, 0), (0, -k), (0, k)]:
            r, c = row + dr, col + dc
            if 0 <= r < n and 0 <= c < m and not visited[r][c]:
                if r == n - 1 and c == m - 1:
                    print(res)
                    exit()
                visited[r][c] = True
                q.append((r, c))
    res += 1

print(-1)
# print(*visited, sep='\n')
