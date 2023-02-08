S = input()
arr = [0] * 30
for i in S :
    arr[ord(i) - ord('a')]+=1

for i in range(26) :
    print(arr[i], end = ' ')