s = input().strip()

a = eval(s)

x = 0
for _ in a:
    if type(_) == int: x+= _
    else: x += sum(_)

print(x)
