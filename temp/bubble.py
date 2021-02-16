def bubbleSort(v[] : int, n : int)
	for i in range(1, n)
		dirty = false
		for j in range(0, n-i)
			if v[i] > v[i+1]
				swap(v[i], v[i+1])
				dirty = true
		if not dirty then break
