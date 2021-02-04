import java.util.*;
public class lab1 {
	static int histogram(int[] hist, int a, int b) {
		if(a==b) return hist[a];

		int c = (a+b)/2;
		int left = histogram(hist, a, c);
		int right = histogram(hist, c+1, b);
		int max = (left>right)?left:right;

		int min = (hist[c]<hist[c+1])?hist[c]:hist[c+1];
		int w = 2;
		if(max < min*w) max = min*w;
		int i = c-1, j = c+2;
		while(i >= a && j <= b) {
			if(hist[i] > hist[j]) {
				if(min > hist[i]) min = hist[i];
				i--;
			}
			else {
				if(min > hist[j]) min = hist[j];
				j++;
			}
			w++;
			if(max < min*w) max = min*w;
		}
		while(i >= a) {
			if(min > hist[i]) min = hist[i];
			i--; w++;
			if(max < min*w) max = min*w;
		}
		while(j <= b) {
			if(min > hist[j]) min = hist[j];
			j++; w++;
			if(max < min*w) max = min*w;
		}
		return max;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] hist = new int[n];
		for(int i = 0; i < n; i++) hist[i] = scan.nextInt();

		System.out.println(histogram(hist, 0, n-1));
	}
}
