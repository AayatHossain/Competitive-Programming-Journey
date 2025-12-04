n = int(input())
a = input()
s = list(a)
i,j = 0, n-1
f=1
while i < j:
    if s[i]==s[j]:
        i+=1
        j-=1
    else:
        f=0
        break
if f:
    print("palindrome")
else:
    print("dont you dare")