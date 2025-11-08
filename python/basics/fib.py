def fib(n):
    if n==0 or n==1:
        return n
    return fib(n-1)+fib(n-2)
    


n = int(input())
l1 = [0]*n
l1[0]=0
l1[1]=1
for i in range(2,n):
    l1[i]=l1[i-1]+l1[i-2]
for i in range(n):
    # print(l1[i]," ")
    print(l1[i], end = " ")
print()
print("Recursive: ", fib(n-1))
