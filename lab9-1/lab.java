import java.util.*;
public class lab {
	static int INF = 1000000000;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[][] d = new int[n+1][n+1];
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = (i==j)?0:INF;
			}
		}
		int k = scan.nextInt();
		for(int i = 0; i < k; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			int w = scan.nextInt();
			d[a][b] = w;
		}
		for(int m = 1; m <= n; m++) {
			for(int u = 1; u <= n; u++) {
				for(int v = 1; v <= n; v++) {
					if(d[u][m] == INF || d[m][v] == INF) continue;
					if(d[u][v] > d[u][m]+d[m][v]) d[u][v] = d[u][m]+d[m][v];
				}
			}
		}
		for(int u = 1; u <= n; u++) {
			for(int v = 1; v <= n; v++) {
				System.out.print(d[u][v]==INF?"INF ":d[u][v]+" ");
			}
			System.out.println("");
		}
	}
}
