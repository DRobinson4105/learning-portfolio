string = input()

index1 = string.index('(')
if string[index1 + 1] != ')':
    print('fix')
    exit()
if string[:index1] != ''.join(reversed(string[index1 + 2:])):
    print('fix')
else:
    print('correct')