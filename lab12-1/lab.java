import java.util.*;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] hist = new int[n];
		for(int i = 0; i < n; i++) hist[i] = scan.nextInt();

		int max = 0;
		for(int i = 0; i < n; i++) {
			if( i > 0 && hist[i-1] >= hist[i]) continue;
			int min = hist[i];
			for(int j = i+1; j < n; j++) {
				if(min > hist[j]) min = hist[j];
				int area = min*(j-i+1);
				if(max < area) max = area;
			}
		}
		System.out.println(max);
	}
}
