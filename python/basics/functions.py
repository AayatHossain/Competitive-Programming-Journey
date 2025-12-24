# def square(a,b):
#     return a**b

# a = int(input())
# b = int(input())
# print(square(a,b))




# def con(a,b):
#     return a+b
# s = con("Aa","yat")
# t = con(2,5)
# print(s,t)






# def printAsc(a):
#     if a==0:
#         return
#     printAsc(a-1)
#     print(a)
    
# n = int(input())
# print(printAsc(n))







#default arguement
# def greet(name = "abcd"):
#     s = f"Hello {name}"
#     return s
# print(greet())




# def numgreet(a = 20):
#     return f"{a} is fixed, cant change it"
# print(numgreet())





# def greet(name = "abcd", greet = "Hello"):
#     s = f"Greeting initiated. {greet}, {name}"
#     return s
# print(greet())




#multiple arguments in one
# def mulAll(*nums):
#     res = 1
#     for i in range(0, len(nums)):
#         res *= nums[i]
#     return res

# print(mulAll(1,2,3,4))




#multiple returns
# def multireturn():
#     return 10,"hello", 2.5
# print(multireturn())



# square = lambda x: x*x
# add = lambda x: x+x
# nothing = lambda x: ""
# addtwo = lambda a,b: a+b
# multwo = lambda a,b: a*b

# print(square(3))
# print(add(3))
# print(nothing(3))
# print(addtwo(2,5))
# print(multwo(2,3))





#this is just a hint, it doesnt force types
# def add(x:int, y:int)->int:
#     return x+y
# print(add(1,2))
# print("st",2)



#typing optional
# from typing import Optional
# def greet(name: Optional[str]=None):
#     if name == None:
#         return "Hello ass"
#     else:
#         return f"Hello {name}"
# print(greet())
# print(greet("aayat"))





#typing union
from typing import Union
def con(name: Union[str, int]):
    return name
print(con("aa"))
print(con(20))