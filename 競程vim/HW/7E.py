i = int(input().strip())
cnt = 0
while i:
    cnt += 1/i
    i -= 1
print("%.4f"%cnt)
