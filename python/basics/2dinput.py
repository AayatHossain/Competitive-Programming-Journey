row, col = map(int, input().split())
mat = [list(map(int, input().split())) for i in range(row)]

for i in range(row):
    for j in range(col):
        print(mat[i][j],end = " ")
    print()