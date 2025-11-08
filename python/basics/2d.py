
row = int(input())
col = int(input())
z=1
mat = [[0]*col for i in range(row)]
for i in range(row):
    for j in range(col):
        mat[i][j]=z
        z+=1

for i in range(row):
    for j in range(col):
        print(mat[i][j], end = " ")
    print()