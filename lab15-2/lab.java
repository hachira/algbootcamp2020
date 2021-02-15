import java.util.*;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n];
		for(int i = 0; i < n; i++) v[i] = scan.nextInt();
		int k = scan.nextInt();
		Arrays.sort(v);
		System.out.println(v[k-1]);
	}
}
