import java.util.*;
public class lab2 {
	static int partition(int[] v, int a, int b) {
		int pivot = v[b];
		int i = a, j = b-1;
		while( true ) {
			while(v[i] <= pivot) i++;
			while(v[j] >= pivot) j--;
			if(i > j) {
				v[b] = v[i]; v[i] = pivot;
				return i;
			}
			int t = v[i]; v[i] = v[j]; v[j] = t; 
		}
	}
	static int kthElement(int[] v, int a, int b, int k) {
		if( a==b ) return v[a];
		int c = partition(v, a, b);
		if( c == k ) return v[c];
		if( c > k ) return kthElement(v, a, c-1, k);
		return kthElement(v, c+1, b, k);
	}
	static int kthElement(int[] v, int n, int k) {
		return kthElement(v, 0, n-1, k-1);
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n];
		for(int i = 0; i < n; i++) v[i] = scan.nextInt();
		int k = scan.nextInt();
		System.out.println(kthElement(v, n, k));
	}
}
