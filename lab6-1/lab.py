def addNode(r, data):
	if r == None:
		r = [data, None, None]
		return r
	if data < r[0]: r[1] = addNode(r[1], data)
	else: r[2] = addNode(r[2], data)
	return r

def searchNode(r, data):
	if r == None: return False
	if r[0] == data: return True
	if data < r[0]: return searchNode(r[1], data)
	return searchNode(r[2], data)

def removeNode(r, data):
	if r == None: return None
	if data < r[0]:
		r[1] = removeNode(r[1], data)
		return r
	if data > r[0]:
		r[2] = removeNode(r[2], data)
		return r
	if r[1] == None and r[2] == None: return None
	if r[1] == None: return r[2]
	if r[2] == None: return r[1]
	tmp = r[2]
	p = None
	while tmp[1] != None:
		p = tmp
		tmp = p[1]
	if p == None: r[2] = tmp[2]
	else: p[1] = tmp[2]
	r[0] = tmp[0]
	return r

root = None
while True:
	x = input().split()
	if x[0] == 'q': break
	data = int(x[1])
	if x[0] == 'a': root = addNode(root, data)
	elif x[0] == 's': print(searchNode(root, data))
	elif x[0] == 'd': root = removeNode(root, data)

