a = list(map(int, input().strip().split()))
cnt = {}
for _ in a:
    try:
        cnt[_]+=1
    except:
        cnt[_] = 1

for key in cnt:
    if not cnt[key] % 2 == 0:
        print(key)
