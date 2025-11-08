n = int(input())
a = list(map(int,input().split()))
mx = 1000000
for i in range(n):
    if a[i] > mx:
        mx = a[i]
c = [0]*(mx+1)

for i in range(n):
    c[a[i]]+=1

for i in range(mx+1):
    while c[i] > 0:
        print(i, end = " ")
        c[i]-=1