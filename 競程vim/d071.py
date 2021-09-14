import bisect

# aaaccceeeee
# bbaccesssss
# acce
def LCS(a1, a2):
    # Location of char (0~127)
    idx = {}
    
    for i,x in enumerate(a2):
        if x in idx:
            idx[x].append(i)
        else:
            idx[x] = [i]
    r = [-1]
    # print(idx)
    for s1 in a1:
        if not s1 in idx: continue
        for n in reversed(idx[s1]):
            if n > r[-1]:
                r.append(n)
            else:
                r[bisect.bisect_left(r, n)] = n

    print(len(r)-1)

LCS(list(input().strip()), list(input().strip()))

