import java.util.*;
public class lab2 {
	static int[] F = { 1, 1, 1, 0 };
	static int MOD = 1000000009;
	static int[] mult(int[] a, int[] b) {
		int[] t = new int[4];
		t[0] = (int)(((long)a[0]*b[0]+(long)a[1]*b[2])%MOD);
		t[1] = (int)(((long)a[0]*b[1]+(long)a[1]*b[3])%MOD);
		t[2] = (int)(((long)a[2]*b[0]+(long)a[3]*b[2])%MOD);
		t[3] = (int)(((long)a[2]*b[1]+(long)a[3]*b[3])%MOD);
		return t;
	}
	static int[] fibo(int n) {
		if(n == 1) return F;
		int[] t = fibo(n/2);
		t = mult(t, t);
		if(n%2==1) t = mult(t, F);
		return t;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		System.out.println(fibo(n)[2]);
	}
}
