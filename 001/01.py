def prime_number(n):
	case = set(range(2, n+1))
	for i in range(2, n+1):
		if i in case:
			case -= set(range(2*i, n+1, i))
	return len(case)

N = int(input())
print(prime_number(N))
