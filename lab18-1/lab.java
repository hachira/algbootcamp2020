import java.util.*;
public class lab {
	static int INF = 1000000000;
	static int min(int a, int b) { return a<b?a:b; }
	static int init(int[] st, int[] v, int r, int s, int e) {
		if(s==e) return st[r] = v[s];
		int c = (s+e)/2;
		return st[r] = min(init(st, v, r*2, s, c), init(st, v, r*2+1, c+1, e));
	}
	static int getMin(int[] st, int r, int s, int e, int bs, int be) {
		if(e < bs || be < s) return INF;
		if(bs <= s && e <= be) return st[r];
		int c = (s+e)/2;
		return min(getMin(st, r*2, s, c, bs, be), 
			getMin(st, r*2+1, c+1, e, bs, be));
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n];
		for(int i = 0; i < n; i++) {
			v[i] = scan.nextInt();
		}
		int[] st = new int[n*4];
		init(st, v, 1, 0, n-1);
		int m = scan.nextInt();
		for(int i = 0; i < m; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			System.out.println(getMin(st, 1, 0, n-1, a-1, b-1));
		}
	}
}
