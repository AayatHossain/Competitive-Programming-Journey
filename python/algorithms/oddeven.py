n = int(input("Enter num bish: \n"))
a = []
for i in range(n):
    a.append(int(input()))
print(a)

odds = []
evens = []
for i in range(n):
    if a[i]&1:
        odds.append(a[i])
    else:
        evens.append(a[i])
print(odds)
print(evens)