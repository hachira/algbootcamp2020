import java.util.*;
public class lab {
	static long init(long[] st, int r, int[] v, int s, int e) {
		if(s == e) return st[r] = v[s];
		int c = (s+e)/2;
		return st[r] = init(st,r*2,v,s,c)+init(st,r*2+1,v,c+1,e);
	}
	static long sum(long[] st, int r, int s, int e, int is, int ie) {
		if(ie < s || e < is) return 0;
		if(is <= s && e <= ie) return st[r];
		int c = (s+e)/2;
		return sum(st,r*2,s,c,is,ie)+sum(st,r*2+1,c+1,e,is,ie);
	}
	static long upt(long[] st, int r, int s, int e, int idx, int v) {
		if(idx < s || e < idx) return st[r];
		if(s==e) return st[r] = v;
		int c = (s+e)/2;
		return st[r] = upt(st,r*2,s,c,idx,v)+upt(st,r*2+1,c+1,e,idx,v);
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n];
		for(int i = 0; i < n; i++) v[i] = scan.nextInt();

		long[] st = new long[4*n];
		init(st, 1, v, 0, n-1);

		int k = scan.nextInt();
		for(int i = 0; i < k; i++) {
			String cmd = scan.next();
			int a = scan.nextInt();
			int b = scan.nextInt();
			if(cmd.equals("s")) System.out.println(sum(st, 1, 0, n-1, a-1, b-1));
			else upt(st, 1, 0, n-1, a-1, b);
		}
	}
}
