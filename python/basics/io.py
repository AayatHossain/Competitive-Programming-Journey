#method 1
# n = int(input("Enter size: "))
# l1 = [2]*n
# for i in range(n):
#     l1[i]=int(input(f"Enter {i}th element: "))
    
# print(l1)


# method 2, input one by one
# m = int(input())
# l1 = [0]*m
# for i in range(m):
#     l1[i]=int(input())
# print(l1)


#method 3 - input in a single line
n = int(input())
l1 = [3]*n
print(l1)
l1= list(map(int, input().split()))
print(l1)