s1 = {5,4,3,3,2,1,1,1,1}
print(s1)

print()
for x in s1:
    print(x)

print()
if 3 in s1:
    print("3 found")
    
if 6 in s1:
    print("6 found")
    
print()
s1.add(10)
s1.remove(2)
print(s1)
