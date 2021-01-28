import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
public class lab {
	static void dfs(int r, int n, int[][] adjMat, boolean[] visited) {
		System.out.println(r+1);
		visited[r] = true;
		for(int i = 0; i < n; i++) {
			if(adjMat[r][i] == 1 && !visited[i]) {
				dfs(i, n, adjMat, visited);
			}
		}
	}
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

		System.out.println("DFS");
		boolean[] visited = new boolean[n];
		dfs(0, n, adjMat, visited);

		System.out.println("BFS");
		Queue<Integer> que = new LinkedList();
		visited = new boolean[n];
		que.add(0);
		visited[0] = true;
		while(!que.isEmpty()) {
			int r = que.remove();
			System.out.println(r+1);
			for(int i = 0; i < n; i++) {
				if(adjMat[r][i] == 1 && !visited[i]) {
					que.add(i);
					visited[i] = true;
				}
			}
		}
	}
}
