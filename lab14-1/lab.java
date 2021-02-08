import java.util.*;
public class lab {
	static void selectionSort(int[] v, int n) {
		for(int i = 0; i < n-1; i++) {
			int min = i;
			for(int j = i+1; j < n; j++) if(v[min] > v[j]) min = j;
			int t = v[i]; v[i] = v[min]; v[min] = t;
		}
	}
	static void insertionSort(int[] v, int n) {
		for(int i = 1; i < n; i++) {
			int last = i-1, key = v[i];
			while( last >= 0 && v[last] > key) {
				v[last+1] = v[last];
				last--;
			}
			v[last+1] = key;
		}
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n];
		for(int i = 0; i < n; i++) v[i] = scan.nextInt();
		for(int i = 0; i < 15; i++) System.out.println(v[i]);
		//selectionSort(v, n);
		insertionSort(v, n);
		for(int i = 0; i < 15; i++) System.out.println(v[i]);
	}
}
