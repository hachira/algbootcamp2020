import heapq
V, E = map(int, input().split())
start = int(input())

adj = {i: [] for i in range(1, V+1)}
for _ in range(E):
    a, b, w = map(int, input().split())
    adj[a].append([b, w])

INF = 1e9
dist = [INF] * (V + 1)

hq = []
heapq.heappush(hq, (0, start))
dist[start] = 0

while hq:
    k, u = heapq.heappop(hq)
    for w, cost in adj[u]:
        if cost + dist[u] < dist[w]:
            dist[w] = cost + dist[u]
            heapq.heappush(hq, (dist[w], w))

for i in range(1, V+1):
    if dist[i] != INF: 
        print(dist[i])
    else:
        print('INF')
