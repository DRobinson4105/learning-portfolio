n = int(input())
arr = list(map(int, input().split()))
res = 0
cur_sum = 0
for i in range(n):
    cur_sum += arr[i]
    res = max(res, cur_sum / (i + 1))

cur_sum = 0
for i in range(n - 1, -1, -1):
    cur_sum += arr[i]
    res = max(res, cur_sum / (n - i))

print(res)

