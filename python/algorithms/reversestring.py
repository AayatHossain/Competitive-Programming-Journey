a = input()
s = list(a) 
n = len(s)
i = 0
j = n-1
while i < j:
    temp = s[i]
    s[i] = s[j]
    s[j] = temp
    i+=1
    j-=1
a = "".join(s)
print(a)