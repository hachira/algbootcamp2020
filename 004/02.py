import sys
import heapq

INF = 1e9
V, E = map(int,sys.stdin.readline().split())

G = [[] for _ in range(V + 1)]
K = int(sys.stdin.readline())

for _ in range(E):
    start, end, distance=map(int,sys.stdin.readline().split())
    G[start].append([distance, end])

result = [INF for _ in range(V + 1)]
result[K] = 0

q = []
heapq.heappush(q, [0, K])


while q:
    dis, end=heapq.heappop(q)

    if result[end] < dis:
        continue
        
    for d, x in G[end]:
        d += dis
        if d < result[x]:
            result[x] = d
            heapq.heappush(q, [d, x])

for i in range(1, V + 1):
    print(result[i] if result[i] != INF else "INF")
