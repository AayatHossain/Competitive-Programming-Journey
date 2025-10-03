list1 = [1,2,3,4,5]
for x in list1:
    print(x,end = " ")
    
    
print()
for i in range(0,5):
    print(list1[i], end=" ")
    
    
print()
for i in range(0,5):
    if(list1[i]&1):
        print("Odd")
    else:
        print("Even")
   
print()     
for x in list1:
    if(x%2==1):
        print("Odd with", x)
    else:
        print("Even with", x)
        
        
print()
for x in list1:
    if(x==1):
        print("Num with", x)
    elif(x==2):
        print("Num with", x)
        

print()
i = 0
while(i<5):
    print(list1[i])
    i+=1
    
