num = newNum = None
length = int(input())
for i in range(length):
    if num is None:
        num = int(input())
    else:
        newNum = int(input())
        if newNum % num == 0:
            print(newNum)
            num = None