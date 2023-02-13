tmp = input()
no = False
ans = False

while True :
    if no :
        break

    if len(tmp) == 0 :
        ans = True
        break

    if tmp[0:2] == "pi" :
        tmp = tmp[2:]
    elif tmp[0:2] == "ka" :
        tmp = tmp[2:]
    elif tmp[0:3] == "chu" :
        tmp = tmp[3:]
    else :
        no = True

if(ans) :
    print("YES")
else :
    print("NO")