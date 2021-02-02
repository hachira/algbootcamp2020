import queue

n, m = map(int, input().split())
maze = [ [0] * m for _ in range(n) ]
for i in range(n):
	s = input()
	for j in range(m):
		if s[j] == '1': maze[i][j] = 1

queue = queue.Queue()
values = [ [0] * m for _ in range(n) ]
hammer = [ [0] * m for _ in range(n) ]

values[0][0] = 1
queue.put((0, 0))
while not queue.empty():
	r, c = queue.get()
	if r == n-1 and c == m-1: break
	diff = [ (0, 1), (1, 0), (0, -1), (-1, 0) ]
	for dr, dc in diff:
		nr, nc = r+dr, c+dc
		if nr < 0 or nr >= n or nc < 0 or nc >= m: continue
		# if hammer was used already
		if hammer[r][c] == 1:
			if maze[nr][nc] == 1: continue
			if values[nr][nc] != 0: continue
			values[nr][nc] = values[r][c]+1
			hammer[nr][nc] = 1
		else:
			if values[nr][nc] != 0 and hammer[nr][nc] == 0: continue
			values[nr][nc] = values[r][c]+1
			hammer[nr][nc] = maze[nr][nc]
		queue.put((nr, nc))
if values[n-1][m-1] == 0: print(-1)
else: print(values[n-1][m-1])
