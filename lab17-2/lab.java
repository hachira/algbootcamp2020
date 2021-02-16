import java.util.*;
public class lab {
	static int backTrack(int limit, int t, int s, int n) {
		if( t == 0 ) {
			if(--n == 0) {
				for(int i = 9; i >= 0; i--) {
					if((s & (1<<i)) != 0) System.out.print(i);
				}
				System.out.println("");
			}
			return n;
		}
		for(int i = 0; i < limit; i++) {
			if((s & (1<<i)) != 0) continue;
			n = backTrack(i, t-1, s | (1<<i), n);
		}
		return n;
	}
	static void backTrack(int n) {
		for(int i = 2; i <= 10; i++) {
			n = backTrack(10, i, 0, n);
		}
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		if( n < 10 ) { System.out.println(n); return; }
		if( n > 1022 ) { System.out.println("-1"); return; }
		backTrack(n-9);
	}
}
