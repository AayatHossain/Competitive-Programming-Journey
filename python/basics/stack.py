stack = []
for i in range(5,10):
    stack.append(i)

print(stack[-1])
while len(stack) > 0:
    print(stack[-1])
    stack.pop()