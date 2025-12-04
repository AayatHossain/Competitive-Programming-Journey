n,k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
l=0
r=n-1
i = -1
while l <= r:
    m = l+(r-l)//2
    if a[m] > k:
        r=m-1
    elif a[m] < k:
        l = m+1
    else:
        i = m
        break
    
if i==-1:
    print("stfu")
else:
    print(i)