public class Main {
	static int pi(int n) { 
		if (n < 2)
			return 0;
		if (n == 2)
			return 1;
		int pcount = 1;
		for (int p = 3; p <= n; p += 2) {
			boolean isPrime = true;
			for (int d = 3; d * d <= p; d += 2) {
				if (p % d == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime)
				pcount++;
		}
		return pcount;
	}

	public static void main(String[] args) {
		int n = 1000000;
		System.out.println(pi(n));
	}

}
