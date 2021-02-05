import java.util.*;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n];
		long[] sum = new long[n+1];		//	accumulated sum
		for(int i = 0; i < n; i++) {
			v[i] = scan.nextInt();
			sum[i+1] = sum[i]+v[i];			//	calculate sum
		}

		int k = scan.nextInt();
		for(int i = 0; i < k; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			System.out.println(sum[b]-sum[a-1]);
		}
	}
}
