import java.util.*;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n];
		for(int i = 0; i < n; i++) {
			v[i] = scan.nextInt();
		}

		//	Block accumulated sum
		long[] asum = new long[n+1]; long sum = 0;
		int q = (int)Math.sqrt(n);
		for(int i = 1; i <= n; i++) {
			sum += v[i-1];
			asum[i] = sum;
			//	If i is at block border, reset sum.
			if( i%q == 0 ) sum = 0;
		}

		int k = scan.nextInt();
		for(int i = 0; i < k; i++) {
			String cmd = scan.next();
			int a = scan.nextInt();
			int b = scan.nextInt();
			if(cmd.equals("s")) {
				sum = asum[b]-asum[a-1];
				int t = ((a-1)/q+1)*q;
				for(int j = t; j < b; j += q) {
					if(j >= a) sum += asum[j];
				}
				System.out.println(sum);
			}
			else {
				v[a-1] = b;
				sum = 0;
				int t = ((a-1)/q)*q+1;
				for(int j = t; j < t+q && j <= n; j++) {
					sum += v[j-1];
					asum[j] = sum;
				}
			}
		}
	}
}
