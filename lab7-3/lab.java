import java.util.Scanner;
public class lab {
	static int findRoot(int[] v, int x) {
		if(v[x] == x) return x;
		return (v[x] = findRoot(v, v[x]));
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n+1];
		for(int i = 1; i <= n; i++) v[i] = i;
		int k = scan.nextInt();
		for(int i = 0; i < k; i++) {
			String cmd = scan.next();
			char c = cmd.charAt(0);
			int a = scan.nextInt();
			int b = scan.nextInt();
			int ra = findRoot(v, a);
			int rb = findRoot(v, b);
			if(c == 'u') {
				v[rb] = ra;
			}
			else if(c == 't') {
				System.out.println(ra==rb);
			}
		}
	}
}
