list1 = [10,13,12,11]
list2 = sorted(list1)
print(list2)
print(list1)
# list3 = list1.sort()//not possible
list1.sort()
print(list1)



list3 = list1
list3.pop()
print(list3)
list3.append(20)
print(list3)
list3.insert(2,200)
print(list3)
print(list3[0],list3[1],list3[2])
list3.remove(11)
print(list3)
list3[2] = 12131
print(list3)