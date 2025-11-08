from collections import deque
q = deque()
for i in range(5):
    q.append(i)
while len(q) > 0:
    print(q[0])
    q.popleft()
