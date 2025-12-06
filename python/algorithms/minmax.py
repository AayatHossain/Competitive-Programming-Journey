n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    print(a[i], end=" ")
    
mx = -float('inf')
mn = float('inf')

for i in range(n):
    if a[i] < mn:
        mn = a[i]
    if a[i] > mx:
        mx = a[i]
print()
print(mn,mx)

