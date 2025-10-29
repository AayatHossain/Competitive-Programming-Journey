from collections import OrderedDict

m1 = {
    "A":5,
    "C":15,
    "B":10
}
print(m1["A"])
print(m1["B"])
print(m1["C"])

m1["A"]+=1
print(m1["A"])

if "A" in m1:
    print(m1["A"])
    
del m1["A"]
# print(m1)


m2 = dict(sorted(m1.items()))
m3 = OrderedDict(sorted(m1.items()))
print(m2)
print(m3)



