n, lph = map(int, input().split())
max_lines = lph * 5
arr = sorted([int(input()) for _ in range(n)])
res = summ = 0
for i in arr:
    if summ + i <= max_lines:
        summ += i
        res += 1
    else:
        break

print(res)