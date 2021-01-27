import java.util.Scanner;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[][] adjMat = new int[n][n];

		int k = scan.nextInt();
		for(int i = 0; i < k; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			adjMat[a-1][b-1] = 1;
			adjMat[b-1][a-1] = 1;
		}

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) System.out.print(adjMat[i][j]+" ");
			System.out.println("");
		}
	}
}
