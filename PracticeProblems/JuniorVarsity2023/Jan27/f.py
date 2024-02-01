string = input()
vow = 'aeiou'
res1 = res2 = 0
for i in string:
    if i in vow:
        res1 += 1
    elif i == 'y':
        res2 += 1

print(res1, res1 + res2)