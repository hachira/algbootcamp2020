import java.util.Scanner;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n+n%2];
		for(int i=0;i<n;i++) v[i] = scan.nextInt();
		if(n%2==1) { v[n]=v[n-1]; n++; }
		for(int i=0; i<n; i+=2) {
			if(v[i]>v[i+1]) {
				int t=v[i];
				v[i]=v[i+1];
				v[i+1]=t;
			}
		}

		int min=v[0], max=v[1];
		for(int i=2; i<n; i+=2) {
			if(min>v[i]) min=v[i];
			if(max<v[i+1]) max=v[i+1];
		}

		System.out.println(""+min+" "+max);
	}
}
